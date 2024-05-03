#ifndef CREADFILE_H
#define CREADFILE_H

#include <stack>
#include <string>

class CReadFile {
private:
    std::stack<std::string> stack_odd;
    std::stack<std::string> stack_even;

public:
    CReadFile();
    void readFromFile(const std::string& filepath);
    std::string getTopOdd() const;
    std::string getTopEven() const;
    bool isEmpty() const;

    // Updated function declarations to return const references
    const std::stack<std::string>& getStackEven() const;
    const std::stack<std::string>& getStackOdd() const;
};

#endif // CREADFILE_H
