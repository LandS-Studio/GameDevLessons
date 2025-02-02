/*
ОБОВ’ЯЗКОВЕ ДОМАШНЄ ЗАВДАННЯ (4 бали)

1. Створити структуру Student з полями name та marks[4]; 
написати функцію, що приймає студента як вхідний параметр та повертає середню оцінку по предметам студента;

2. створити масив of Student; 

3. функція, що повертає посилання(pointer) на найуспішнішого студента у масиві;

4. функція, яка підраховує кількість студентів, середня оцінка яких більше ніж вхідний параметр N;

ДОДАТКОВЕ ДОМАШНЄ ЗАВДАННЯ (1 бал)

5. функція, яка повертає масив з N% найуспішніших студентів:

void getBestStudents(Student* inStudents, unsigned inSize, Student* outStudents, unsigned& outSize, unsigned percent);

6. функція, що сортує студентів у масиві по критерію середньої оцінки;
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// FOR STEP 1
// Sructure of student
struct Student {
    std::string name;
    int marks[4];
};

// Function that returns the average mark of the student
double averageMark(Student student) {
    double sum = 0;
    for (int i = 0; i < 4; ++i) {
        sum += student.marks[i];
    }
    return sum / 4;
}

// FOR STEP 3
// Function that returns the pointer to the most successful student in the array
Student* mostSuccessfulStudent(Student* students, const int size) {
    Student* successfulStudent = &students[0];
    for (int i = 1; i < size; ++i) {
        if (averageMark(students[i]) > averageMark(*successfulStudent)) {
            successfulStudent = &students[i];
        }
    }
    return successfulStudent;
}

// FOR STEP 4
// Function that returns the number of students whose average mark is greater than the input parameter N
int countStudents(Student* students, const int size, const double N) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (averageMark(students[i]) > N) {
            ++count;
        }
    }
    return count;
}

// FOR STEP 5
// Function compare two students by average mark
bool compareStudents(Student a, Student b) {
    return averageMark(a) > averageMark(b);
}

// Function that returns the array of N% best students
void getBestStudents(Student* inStudents, unsigned inSize, Student* outStudents, unsigned& outSize, const unsigned percent) {
    outSize = inSize * percent / 100;
    
    std::vector<Student> sortedStudents(inStudents, inStudents + inSize);
    std::sort(sortedStudents.begin(), sortedStudents.end(), compareStudents);

    unsigned count = (percent * inSize) / 100;
    outSize = std::min(count, inSize);
    
    for (int i = 0; i < outSize; ++i) {
        outStudents[i] = sortedStudents[i];
    }
}


int main() {

    // FOR STEP 1-4
    // Create an array of students
    Student students[4] = {
        {"Ivan", {5, 4, 3, 5}},
        {"Petro", {4, 4, 4, 4}},
        {"Vasyl", {3, 3, 3, 3}},
        {"Bob", {1, 2, 3, 4}}
    };

    // Print the average mark of each student
    for (int i = 0; i < 4; ++i) {
        std::cout << students[i].name << " - " << averageMark(students[i]) << std::endl;
    }
    std::cout << std::endl;

    // Print the most successful student
    std::cout << "The most successful student is " << mostSuccessfulStudent(students, 4)->name << std::endl;
    std::cout << std::endl;
    
    // Print the number of students whose average mark is greater than 3
    std::cout << "The number of students whose average mark is greater than 3 is " << countStudents(students, 4, 3) << std::endl;
    std::cout << std::endl;

    // FOR STEP 5
    unsigned inSize = sizeof(students) / sizeof(students[0]);
    unsigned outSize;
    Student outStudents[4];

    unsigned persent = 50;
    getBestStudents(students, inSize, outStudents, outSize, persent);

    // Print the array of N% best students
    std::cout << persent << "% best students (" << outSize << " studens):" << std::endl;
    for (unsigned i = 0; i < outSize; ++i) {
        std::cout << outStudents[i].name << " with average " << averageMark(outStudents[i]) << std::endl;
    }
    
    return 0;
}
