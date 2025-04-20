// Mia Palmer's program for CSC1060 project.
// This program is a mystery game based on the board game Clue.
// It loads suspect clues from a file and allows the user to make guesses.
// The user has up to four chances to guess who the murderer is.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    // Input: The user gives their name and makes guesses about who the murderer is.
    // Process: The program reads a file that contains clues for each suspect.
    // A random suspect is selected as the murderer.
    // Each incorrect guess gives a clue about the murderer.
    // Output: The user is told if they solved the case or not.

    // Declare the suspects.
    vector<string> charArr = {
        "Miss Scarlet", "Mr. Green", "Mrs. Peacock",
        "Professor Plum", "Colonel Mustard", "Mrs. White"
    };

    // Create a map to store clues for each suspect.
    map<string, vector<string>> clues;
    string chosenChar, userName, userGuess;
    bool win = false;
    int guesses = 0;

    // Open the file that contains the clues.
    ifstream clueFile("clue_data.txt");
    if (!clueFile) {
        cerr << "Error: Could not open clue_data.txt" << endl;
        return 1;
    }

    // Read the clues from the file and store them in the map.
    string line;
    while (getline(clueFile, line)) {
        string name = line;
        vector<string> clueSet;
        for (int i = 0; i < 3; ++i) {
            getline(clueFile, line);
            clueSet.push_back(line);
        }
        clues[name] = clueSet;
        getline(clueFile, line); // Skip the blank line between entries.
    } // End while.
    clueFile.close();

    // Ask the user for their name and welcome them to the game.
    cout << "\nPlease enter your name to start the game: ";
    getline(cin, userName);

    // Introduction and suspect info.
    cout << "\n\nWelcome to Miss Mia's Mystery Mansion!\n\n";
    cout << "I am guessing you are Detective " << userName << " here for the homicide case about the unfortunate victim, Mr. Boddy...\n\n";
    cout << "I wish I could give you a better welcome but I should probably let you get to work.\n\n";
    cout << "Below is all the information I have gathered on everyone that was here on that terrible night.\n\n";
    cout << "You will need to solve this case quickly within four accusations or you might be next...Good luck!\n\n\n";

    // Display the description of each suspect.
    cout << "Suspects information:\n\n";
    cout << "Miss Scarlet is known for her beauty. But don't let it fool you, she is quite intelligent as well. She also is a great cook.\n\n";
    cout << "Mr. Green is the sneakiest of the group. He can get himself out of any bad situation by simply disappearing without a trace. Some say he uses the vents.\n\n";
    cout << "Mrs. Peacock is the kindest person you will meet. Always ready to help fix something for a friend in need with her trusty wrench. The only problem is she will expect something in return.\n\n";
    cout << "Professor Plum is the smartest of the bunch. He never puts down that old book and requests a candlestick to read each night\n\n";
    cout << "Colonel Mustard does not talk too much. You will not be able to catch him off guard so be careful if you believe he is the one who did it. Not to mention he always has his gun.\n\n";
    cout << "Mrs. White is the one who seems to know everyone's secrets. Ask her anything, but don't expect her to tell you the truth.\n\n\n";

    // Pick a random murderer from the suspect list.
    srand(time(0));
    chosenChar = charArr[rand() % charArr.size()];

    // Game loop: allow up to four guesses.
    while (userGuess != chosenChar && guesses < 4) {
        cout << "Please write who you think the murderer is: ";
        getline(cin, userGuess);

        // Check if the user's guess is valid.
        bool validGuess = false;
        for (const string& name : charArr) {
            if (userGuess == name) {
                validGuess = true;
                break;
            }
        } // End for.

        if (!validGuess) {
            // Tell the user if the name is not valid.
            cout << "Invalid name. Please choose from the list of suspects." << endl;
            continue; // Do not count this as a guess.
        }

        // If guess is correct, end the game.
        if (userGuess == chosenChar) {
            win = true;
            break;
        } else {
            // Give a clue if the guess is wrong.
            if (guesses < clues[chosenChar].size()) {
                cout << "\n" << clues[chosenChar][guesses] << "\n\n";
            }
            guesses++;
        }
    } // End while.

    // Display the result of the game.
    if (win) {
        cout << "\nCongratulations! You caught " << chosenChar << " and solved the mystery!\n\n";
    } else {
        cout << "\nUh oh! You got caught...The murderer was: " << chosenChar << ". Better luck next time!\n\n";
    }

    return 0;
} // End main().
