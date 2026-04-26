/*
 * Name: Brayan Tellez
 * Course: CS 210
 * Assignment: Project Two - Airgead Banking App
 * Date: April 6, 2026
 * Description: This file contains the function definitions for the InvestmentCalculator class.
 */

#include <iostream>
#include <iomanip>
#include <limits>
#include "InvestmentCalculator.h"

using namespace std;

// constructor sets everything to 0 at the start
InvestmentCalculator::InvestmentCalculator() {
    initialInvestment = 0.0;
    monthlyDeposit = 0.0;
    annualInterest = 0.0;
    numberOfYears = 0;
}

// this runs the main parts of the program
void InvestmentCalculator::run() {
    getUserInput();
    cout << endl;
    displayInputScreen();
    cout << endl;
    cout << "Press Enter to continue...";
    cin.get();
    cout << endl;

    displayReportWithoutMonthlyDeposit();
    cout << endl;
    displayReportWithMonthlyDeposit();
}

// checks if the user entered a valid number
double InvestmentCalculator::getValidatedDouble(const char* prompt) {
    double value;

    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (value < 0) {
            cout << "Invalid input. Please enter 0 or a positive number." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// checks if the user entered a valid whole number
int InvestmentCalculator::getValidatedInt(const char* prompt) {
    int value;

    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a whole number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (value <= 0) {
            cout << "Invalid input. Please enter a number greater than 0." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// asks the user for the investment values
void InvestmentCalculator::getUserInput() {
    initialInvestment = getValidatedDouble("Initial Investment Amount: ");
    monthlyDeposit = getValidatedDouble("Monthly Deposit: ");
    annualInterest = getValidatedDouble("Annual Interest (%): ");
    numberOfYears = getValidatedInt("Number of Years: ");
}

// shows the values entered by the user
void InvestmentCalculator::displayInputScreen() const {
    cout << "**********************************" << endl;
    cout << "********** Data Input ************" << endl;
    cout << fixed << setprecision(2);
    cout << "Initial Investment Amount: $" << initialInvestment << endl;
    cout << "Monthly Deposit: $" << monthlyDeposit << endl;
    cout << "Annual Interest: %" << annualInterest << endl;
    cout << "Number of Years: " << numberOfYears << endl;
    cout << "**********************************" << endl;
}

// report for balance and interest without monthly deposits
void InvestmentCalculator::displayReportWithoutMonthlyDeposit() const {
    double currentBalance = initialInvestment;

    cout << "  Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "==========================================================" << endl;
    cout << left << setw(10) << "Year"
         << setw(25) << "Year End Balance"
         << setw(25) << "Year End Earned Interest" << endl;

    for (int year = 1; year <= numberOfYears; year++) {
        double yearlyInterest = 0.0;

        for (int month = 1; month <= 12; month++) {
            double monthlyInterest = currentBalance * ((annualInterest / 100) / 12);
            yearlyInterest += monthlyInterest;
            currentBalance += monthlyInterest;
        }

        cout << left << setw(10) << year
             << "$" << setw(24) << fixed << setprecision(2) << currentBalance
             << "$" << setw(24) << fixed << setprecision(2) << yearlyInterest << endl;
    }
}

// report for balance and interest with monthly deposits
void InvestmentCalculator::displayReportWithMonthlyDeposit() const {
    double currentBalance = initialInvestment;

    cout << "  Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "=======================================================" << endl;
    cout << left << setw(10) << "Year"
         << setw(25) << "Year End Balance"
         << setw(25) << "Year End Earned Interest" << endl;

    for (int year = 1; year <= numberOfYears; year++) {
        double yearlyInterest = 0.0;

        for (int month = 1; month <= 12; month++) {
            currentBalance += monthlyDeposit;
            double monthlyInterest = currentBalance * ((annualInterest / 100) / 12);
            yearlyInterest += monthlyInterest;
            currentBalance += monthlyInterest;
        }

        cout << left << setw(10) << year
             << "$" << setw(24) << fixed << setprecision(2) << currentBalance
             << "$" << setw(24) << fixed << setprecision(2) << yearlyInterest << endl;
    }
}