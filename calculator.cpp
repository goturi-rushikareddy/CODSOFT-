#include <iostream>
#include <limits> // To clear input buffer

using namespace std;

// Function to display the menu
void displayMenu() {
    cout << "Select operation:\n";
    cout << "1. Add\n";
    cout << "2. Subtract\n";
    cout << "3. Multiply\n";
    cout << "4. Divide\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Function to perform the operations
void performOperation(int choice, double num1, double num2) {
    switch (choice) {
        case 1:
            cout << "Result: " << num1 + num2 << endl;
            break;
        case 2:
            cout << "Result: " << num1 - num2 << endl;
            break;
        case 3:
            cout << "Result: " << num1 * num2 << endl;
            break;
        case 4:
            if (num2 == 0) {
                cout << "Error! Division by zero.\n";
            } else {
                cout << "Result: " << num1 / num2 << endl;
            }
            break;
        default:
            cout << "Invalid choice!\n";
    }
}

int main() {
    int choice;
    double num1, num2;

    while (true) {
        displayMenu();
        cin >> choice;

        // Clear the input buffer if a non-numeric value is entered
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        if (choice == 5) {
            cout << "Exiting the calculator...\n";
            break;
        }

        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        // Check for invalid number input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter numbers.\n";
            continue;
        }

        performOperation(choice, num1, num2);
    }

    return 0;
}
