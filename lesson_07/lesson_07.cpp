#include <iostream>
#include <cstdlib>
#include <ctime>

std::string getNameForChoice(char choice) {
    switch (choice) {
        case 'r': return "Rock";
        case 'p': return "Paper";
        case 's': return "Scissors";
        default: return "Unknown";
    }
}

char getChoiceByComp() {
    int randomValue = rand() % 3;
    switch (randomValue) {
        case 0: return 'r';
        case 1: return 'p';
        case 2: return 's';
        default: return 'r';
    }
}

int main() {
    srand((time(0)));
    int totalRounds;

    while (true) {
        std::cout << "Enter the number of rounds (-1 to EXIT): ";
        std::cin >> totalRounds;

        if (totalRounds == -1) {
            std::cout << "Game is ended!" << std::endl;
            break;
        }

        if (totalRounds <= 0) {
            std::cout << "ERR: The number of rounds must be positive" << std::endl;
            continue;
        }

        int userWins = 0, compWins = 0, ties = 0;

        for (int i = 0; i < totalRounds; ++i) {
            char userChoice;
            std::cout << "ROUND " << (i + 1) << ": Enter your choice (r - rock, p - paper, s - scissors): ";
            std::cin >> userChoice;

            char computerChoice = getChoiceByComp();
            
            if (userChoice != 'r' && userChoice != 'p' && userChoice != 's' ||
                computerChoice != 'r' && computerChoice != 'p' && computerChoice != 's') {
                std::cout << "ERR: Incorrect selection. Please try again" << std::endl;
                --i;
                continue;
            }

            
            
            std::cout << "Your choice: " << getNameForChoice(userChoice) << ", choice of computer: " << getNameForChoice(computerChoice) << std::endl;

            // GAME
            if (userChoice == computerChoice) {
                std::cout << "TIES!" << std::endl;
                ++ties;
            } else if ((userChoice == 'r' && computerChoice == 's') ||
                       (userChoice == 'p' && computerChoice == 'r') ||
                       (userChoice == 's' && computerChoice == 'p')) {
                std::cout << "YOU WIN!" << std::endl;
                ++userWins;
            } else {
                std::cout << "YOU LOST!" << std::endl;
                ++compWins;
            }
        }

        // GAME STATS
        std::cout << std::endl << "Game results:" << std::endl;
        std::cout << "User wins: " << userWins << std::endl;
        std::cout << "Comp wins: " << compWins << std::endl;
        std::cout << "Ties: " << ties << std::endl;

        if (userWins > compWins) {
            std::cout << "Final result: You win!" << std::endl;
        } else if (userWins < compWins) {
            std::cout << "Final result: Comp win!" << std::endl;
        } else {
            std::cout << "Final result: Tie!" << std::endl;
        }

        std::cout << "--------------------------------------\n";
    }

    return 0;
}
