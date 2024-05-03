import FantasyMovies 1.0
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 400
    height: 300
    title: "Fantasy Movies"

    ColumnLayout {
        anchors.centerIn: parent // Center the column layout in the parent
        spacing: 10

        Text {
            text: "Enter a number:"
        }

        TextField {
            id: userInputField
            width: 100
            validator: IntValidator {}
            placeholderText: "Number"
            Layout.alignment: Qt.AlignHCenter // Center the text field horizontally
        }

        Button {
            text: "OK"
            onClicked: {
                var userInput = parseInt(userInputField.text)
                if (!isNaN(userInput)) {
                    fantasyMovies.processUserInput(userInput)
                }
            }
            Layout.alignment: Qt.AlignHCenter // Center the button horizontally
        }

        Text {
            id: movieTitle
            text: "Surprise Movie: "
        }

        Button {
            text: "Quit"
            onClicked: Qt.quit()
            Layout.alignment: Qt.AlignHCenter // Center the button horizontally
        }
    }

    CFantasyMovies {
        id: fantasyMovies

        onMovieSelected: {
            updateMovieTitle(movie)
        }
    }

    function updateMovieTitle(movie) {
        console.log("Updating movie title:", movie)
        movieTitle.text = "Surprise Movie: " + movie
    }
}
