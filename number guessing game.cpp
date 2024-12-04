#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>  // For numeric_limits

using namespace std;

int main() {
    // Initialize random seed
    srand(time(0));

    // Generate a random number between 1 and 100
    int numberToGuess = rand() % 100 + 1;
    int userGuess;
    int attempts = 0;
    const int maxAttempts = 10;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "You have " << maxAttempts << " attempts to guess the number." << endl;

    // Game loop
    while (attempts < maxAttempts) {
        cout << "Attempt " << (attempts + 1) << "/" << maxAttempts << ": Enter your guess: ";
        cin >> userGuess;

        // Validate the input
        if (cin.fail()) {
            cin.clear();  // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
            cout << "Invalid input! Please enter a number between 1 and 100.\n";
            continue;
        }

        // Check if the guess is within the valid range
        if (userGuess < 1 || userGuess > 100) {
            cout << "Please enter a number between 1 and 100.\n";
            continue;
        }

        attempts++;

        if (userGuess > numberToGuess) {
            cout << "Too high! Try again." << endl;
        } else if (userGuess < numberToGuess) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number " << numberToGuess << " in " << attempts << " attempts." << endl;
            break;
        }

        // Check if the user has exhausted all attempts
        if (attempts == maxAttempts) {
            cout << "Sorry, you've used all your attempts. The correct number was " << numberToGuess << "." << endl;
        }
    }

    return 0;
}
