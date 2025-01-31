/*
* Word Guessing Game
* Known issues
* 1. Words with invalid characters in the database may be skipped without an error message.
* 2. No mechanism to save the number of attempts after restarting the game.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <unordered_map>

// File names for saving the game status and word database.
const std::string WORD_OF_THE_DAY_STATUS_FILE = "word_of_the_day_status.txt";
const std::string WORDS_DATABASE_FILE = "words_database.txt";

// Return the current day of the year
int getCurrentDay() {
    const std::time_t now = std::time(nullptr);
    const std::tm* tmObj = std::localtime(&now);
    return tmObj->tm_yday;
}

// Loads words from a file, filtering only 5-letter words consisting of letters.
std::vector<std::string> loadWordsFromFile(const std::string& filename){
    std::vector<std::string> words;
    std::ifstream file(filename);
    if (file.is_open()){
        std::string word;
        while (file >> word){
            if (word.size() == 5 && all_of(word.begin(), word.end(), ::isalpha)){ //
                std::transform(word.begin(), word.end(), word.begin(), ::tolower);
                words.push_back(word);
            }
        }
        file.close();
    } else {
        std::cerr << "ERROR: Could not open " << filename << std::endl;
    }
    return words;
}

// Returns the word of the day based on the day number.
std::string getWorldOfTheDay(const std::vector<std::string>& words, int dayNumber){
    return words[dayNumber - 1];
}

// Checks if the word of the day is available for the current day.
bool isWordOfTheDayAvailable(){
    std::ifstream file(WORD_OF_THE_DAY_STATUS_FILE);
    if (!file.is_open()) return true;

    int lastPlayedDay;
    file >> lastPlayedDay;
    file.close();

    return lastPlayedDay != getCurrentDay();
}

// Marks the word of the day as used, writing the current day to the file.
void markWordOfTheDayAsPlayed(){
    std::ofstream file(WORD_OF_THE_DAY_STATUS_FILE, std::ios::trunc); // Truncates the file
    if (file.is_open()){
        file << getCurrentDay();
        file.close();
    }
}

// Prints the result of the guess, showing correct letters in correct and wrong positions.
void printResult(const std::string& guess, const std::string& secret){
    std::unordered_map<char, int> secretMap;

    // Count occurrences of each letter in the secret word
    for (char c : secret) {
        secretMap[c]++;
    }

    std::string result(guess.size(), '*');
    std::vector<bool> matched(secret.size(), false);

    // Check for correct letters in correct positions
    for (int i = 0; i < guess.size(); ++i){
        if (guess[i] == secret[i]){
            result[i] = toupper(guess[i]);
            matched[i] = true;
            secretMap[guess[i]]--;
        }
    }

    // Check for correct letters in wrong positions
    for (int j = 0; j < guess.size(); ++j){
        if (result[j] == '*' && secretMap[guess[j]] > 0){
            result[j] = tolower(guess[j]);
            secretMap[guess[j]]--;
        }
    }

    std::cout << "RESULT: " << result << std::endl << std::endl;
}

// Plays the game, allowing the user to guess the word.
void playGame(const std::vector<std::string>& words){
    // TODO: Add a timer to limit the time for guessing or limit the number of attempts. 
    
    int choice = -1, attempts = 0;
    std::string guessWord, secretWord;
    
    std::cout << "SELECT GAME MODE: " << std::endl;
    std::cout << "1. Random Word" << std::endl;
    std::cout << "2. Word of the Day" << std::endl;
    std::cout << "0. Exit" << std::endl << std::endl;

    // Game mode selection
    while (true) {
        std::cout << "Choice: ";
        std::cin >> choice;
        
        if (choice == 0){
            std::cout << "Thank you for playing!" << std::endl;
            return;
        }
        
        if (choice == 1){
            srand(static_cast<unsigned int>(std::time(nullptr)));
            secretWord = words[rand() % words.size()];
            break;
        }
        
        if (choice == 2) {
            if (!isWordOfTheDayAvailable()){
                std::cout << "The Word of the Day has already been guessed. Try again tomorrow!" << std::endl;
                continue;
            }
            secretWord = getWorldOfTheDay(words, getCurrentDay());
            if (secretWord.empty()){
                std::cout << "ERROR: Could not load Word of The Day. Existing." << std::endl;
                continue;
            }
            break;
        }

        std::cout << "WARNING: Invalid choice! Existing." << std::endl;
        
    }

    std::cout << std::endl;
    std::cout << "Welcome! Guess the 5-letter word." << std::endl << std::endl;

    // Game loop
    while(true){
        std::cout << "ENTER:  ";
        std::cin >> guessWord;

        if (guessWord.size() != 5 || !all_of(guessWord.begin(), guessWord.end(), ::isalpha)){
            std::cout << "WARNING: Please enter a valid 5-letter word." << std::endl;
            continue;
        }

        std::transform(guessWord.begin(), guessWord.end(), guessWord.begin(), ::tolower);
        ++attempts;

        if (guessWord == secretWord){
            std::cout << "RESULT: " << secretWord << std::endl;
            std::cout << "CONGRATULATIONS! You guessed the word in " << attempts << " attempts!" << std::endl << std::endl;
            if (choice == 2) markWordOfTheDayAsPlayed();
            break;
        }

        printResult(guessWord, secretWord);
    }

    // Replay the game
    std::cout << "Do you want to play again? (y/n): ";
    char replay;
    std::cin >> replay;
    if (replay == 'y' || replay == 'Y') {
        playGame(words);
    } else {
        std::cout << "Thank you for playing!" << std::endl;
    }
}

int main() {
    // TODO: Shuffle the words in the database when a full year (365-366 days) has passed to ensure that the word for day 1 does not repeat.
    
    std::vector<std::string> words = loadWordsFromFile(WORDS_DATABASE_FILE);
    if (words.empty()){
        std::cerr << "ERROR: Word database is empty or could not be loaded." << std::endl;
        return 1;
    }
    
    playGame(words);
    return 0;
    
}
