#include "CReadFile.h"
#include <iostream>
#include <fstream>

CReadFile::CReadFile() {}

void CReadFile::readFromFile(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filepath << std::endl;
        return;
    }

    std::string title;
    int sequence_number = 1;

    while (std::getline(file, title)) {
        if (sequence_number % 2 == 0) {
            stack_even.push(title);
        } else {
            stack_odd.push(title);
        }
        sequence_number++;
    }

    file.close();
}

std::string CReadFile::getTopOdd() const {
    if (!stack_odd.empty()) {
        return stack_odd.top();
    } else {
        return "No movie available in the odd stack";
    }
}

std::string CReadFile::getTopEven() const {
    if (!stack_even.empty()) {
        return stack_even.top();
    } else {
        return "No movie available in the even stack";
    }
}

bool CReadFile::isEmpty() const {
    return (stack_odd.empty() && stack_even.empty());
}

// Updated function definitions to return const references
const std::stack<std::string>& CReadFile::getStackEven() const {
    return stack_even;
}

const std::stack<std::string>& CReadFile::getStackOdd() const {
    return stack_odd;
}
