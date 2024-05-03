#ifndef CFANTASYMOVIES_H
#define CFANTASYMOVIES_H

#include <QObject>
#include <string>

class CFantasyMovies : public QObject {
    Q_OBJECT
public:
    explicit CFantasyMovies(QObject *parent = nullptr);

signals:
    void movieSelected(const QString& movie);

public slots:
    void processUserInput(int userInput);
    void selectRandomMovie(bool isEven); // Add this declaration
};

#endif // CFANTASYMOVIES_H
