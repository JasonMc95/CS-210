// Name: Jason McDaniel
// Date: 6-7-2024

#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>

using namespace std;

// Function to validate that input is a positive real number
double getPositiveInput(const string& prompt) {
    double value;
    while (true) {
        // Prompt the user for input
        cout << prompt;
        cin >> value;

        // Check if input is valid
        if (cin.fail() || value <= 0) {
            // Clear error flags and ignore invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // Display error message
            cout << "Invalid input. Please enter a positive number.\n";
        }
        else {
            // Clear input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // Return valid input
            return value;
        }
    }
}

// Function to calculate and display results
void calculateAndDisplay(double initialAmount, double monthlyDeposit, double annualInterest, int numYears) {
    double balanceNoDeposits = initialAmount;
    double balanceWithDeposits = initialAmount;
    double monthlyInterestRate = (annualInterest / 100) / 12;
    stringstream ss;

    // Set output precision for monetary values
    cout << fixed << setprecision(2);
    ss << fixed << setprecision(2);


    // Header for the first scenario: no additional monthly deposits
    cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
    cout << "======================================================\n";
    cout << "  " << "Year";
    cout << "      " << "Year End Balance";
    cout << "     " << "Year End Earned Interest" << "   \n";


    // Calculate and display for each year
    for (int year = 1; year <= numYears; ++year) {
        double yearEndInterestNoDeposits = 0.0;

        // Calculate interest for 12 months without additional deposits
        for (int month = 1; month <= 12; ++month) {
            double monthlyInterest = balanceNoDeposits * monthlyInterestRate;
            yearEndInterestNoDeposits += monthlyInterest;
            balanceNoDeposits += monthlyInterest;
        }

        // Display year-end balance and earned interest
        cout << setw(6) << year;

        ss.str("");
        ss.clear();

        ss << "$" << balanceNoDeposits;
        cout << setw(22) << ss.str();

        ss.str("");
        ss.clear();

        // cout << " $" << yearEndInterestNoWithDeposits;
        ss << "$" << yearEndInterestNoDeposits;
        cout << setw(29) << ss.str();

        cout << endl;
    }

    // Header for the second scenario: with additional monthly deposits
    cout << "\nBalance and Interest With Additional Monthly Deposits\n";
    cout << "======================================================\n";
    cout << "  " << "Year";
    cout << "      " << "Year End Balance";
    cout << "     " << "Year End Earned Interest" << "   \n";

    // Calculate and display for each year
    for (int year = 1; year <= numYears; ++year) {
        double yearEndInterestWithDeposits = 0.0;

        // Calculate interest for 12 months with additional deposits
        for (int month = 1; month <= 12; ++month) {
            double monthlyInterest = (balanceWithDeposits + monthlyDeposit) * monthlyInterestRate;
            yearEndInterestWithDeposits += monthlyInterest;
            balanceWithDeposits += monthlyDeposit + monthlyInterest;
        }

        ss.str("");
        ss.clear();

        // Display year-end balance and earned interest
        cout << setw(6) << year;

        ss << "$" << balanceWithDeposits;
        cout << setw(22) << ss.str();

        ss.str("");
        ss.clear();

        // cout << " $" << yearEndInterestWithDeposits;
        ss << "$" << yearEndInterestWithDeposits;
        cout << setw(29) << ss.str();

        cout << endl;
    }
}

int main() {
    char continueOption;
    do {
        // Prompt user for inputs
        double initialAmount = getPositiveInput("Initial Investment Amount: $ ");
        double monthlyDeposit = getPositiveInput("Monthly Deposit: $ ");
        double annualInterest = getPositiveInput("Annual Interest (in %): ");
        int numYears = static_cast<int>(getPositiveInput("Number of Years: "));

        // Call function to calculate and display results
        calculateAndDisplay(initialAmount, monthlyDeposit, annualInterest, numYears);

        // Ask user if they want to try again
        cout << "\nWould you like to try again with different values? (y/n): ";
        cin >> continueOption;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    } while (tolower(continueOption) == 'y');

    // Display exit message
    cout << "Thank you for using the Airgead Banking App!\n";

    return 0;
}