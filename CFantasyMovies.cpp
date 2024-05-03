#include "CFantasyMovies.h"
#include "CReadFile.h"
#include "CRandom.h"
#include <QDebug> // Add include for qDebug

CFantasyMovies::CFantasyMovies(QObject *parent) : QObject(parent) {}

void CFantasyMovies::processUserInput(int userInput) {
    bool isEven = (userInput % 2 == 0);
    qDebug() << "Input is even:" << isEven;
    selectRandomMovie(isEven);
}

void CFantasyMovies::selectRandomMovie(bool isEven) {
    QString selectedMovie;

    CReadFile reader;

    // Determine which stack to use based on isEven flag
    const std::stack<std::string>& stack = (isEven ? reader.getStackEven() : reader.getStackOdd());

    // Check if the selected stack is empty
    if (stack.empty()) {
        // Handle empty stacks here
        return;
    }

    // Use CRandom class to generate a random index within the size of the stack
    CRandom random;
    int index = random.getRandomInt(0, stack.size() - 1);

    // Temporary stack to store items on top of the selected movie
    std::stack<std::string> stack_temp = stack;

    // Move items on top of the selected movie to stack_temp
    for (int i = 0; i < index; ++i) {
        stack_temp.pop();
    }

    // Retrieve the selected movie
    selectedMovie = QString::fromStdString(stack_temp.top());
    stack_temp.pop();

    // Move items from stack_temp back to the original stack
    while (!stack_temp.empty()) {
        stack_temp.pop();
    }

    qDebug() << "Selected movie: " << selectedMovie;

    emit movieSelected(selectedMovie);
}
