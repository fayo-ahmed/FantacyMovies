#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "CReadFile.h"
#include "CFantasyMovies.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    // Register CFantasyMovies as a QML type
    qmlRegisterType<CFantasyMovies>("FantasyMovies", 1, 0, "CFantasyMovies");

    // Create an instance of CReadFile
    CReadFile reader;

    // Specify the absolute path to input.txt
    std::string filepath = "C:/Users/17633/OneDrive/Documents/FantasyMovies/input.txt";

    // Read movie titles from input.txt
    reader.readFromFile(filepath);

    // Create CFantasyMovies instance
    CFantasyMovies fantasyMovies;

    // Create QML engine
    QQmlApplicationEngine engine;

    // Expose CFantasyMovies instance to QML
    engine.rootContext()->setContextProperty("fantasyMovies", &fantasyMovies);

    // Load the QML file directly from file system
    const QUrl url(QStringLiteral("file:///C:/Users/17633/OneDrive/Documents/FantasyMovies/Main.qml"));
    engine.load(url);

    return app.exec();
}
