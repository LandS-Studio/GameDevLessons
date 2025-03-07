#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <stack>

// TASK 1
unsigned int uniqueWordsCount(const std::string& line) {
    std::set<std::string> uniqueWords;
    std::istringstream stream(line);
    std::string word;

    while (stream >> word) {
        uniqueWords.insert(word);
    }

    return uniqueWords.size();
}

// TASK 2
std::string mostOccureWord(const std::string& line) {
    std::map<std::string, int> wordCount;
    std::istringstream stream(line);
    std::string word;

    while (stream >> word) {
        ++wordCount[word];
    }

    std::string mostOccured;
    int maxCount = 0;
    for (const auto& pair : wordCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostOccured = pair.first;
        }
    }

    return mostOccured;
}

// TASK 3
bool areBraketsBalanced(const std::string& line) {
    std::stack<char> stack;
    for (char ch : line) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack.empty()) {
                return false;
            }

            char top = stack.top();
            stack.pop();
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }

    return stack.empty();
}

// TASK 4
struct Node {
    int data;
    Node* next;
};

bool has_cycle(Node* head) {
    if (head == nullptr) {
        return false;
    }
    
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    // TASK 1
    std::string line = "Hello world! Bye! Hello Bye! Hello world! Hey!";
    std::cout << "Unique words count: " << uniqueWordsCount(line) << std::endl;

    // TASK 2
    std::cout << "Most occured word: " << mostOccureWord(line) << std::endl;

    // TASK 3
    std::string str1 = "{ [()][ ] }()";
    std::string str2 = "[{]}";
    std::cout << (areBraketsBalanced(str1) ? "OK" : "NOT OK") << std::endl;
    std::cout << (areBraketsBalanced(str2) ? "OK" : "NOT OK") << std::endl;

    // TASK 4
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = head;

    std::cout << (has_cycle(head) ? "Cycle detected" : "No cycle detected") << std::endl;

    // Free memory
    head->next->next->next = nullptr;
    delete head->next->next;
    delete head->next;
    delete head;
    
    return 0;
}
