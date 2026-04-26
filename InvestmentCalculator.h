/*
 * Name: Brayan Tellez
 * Course: CS 210
 * Assignment: Project Two - Airgead Banking App
 * Date: April 6, 2026
 * Description:
 * This header file sets up the InvestmentCalculator class.
 * It includes the variables and function declarations
 * that are used in the program.
 */

#ifndef INVESTMENTCALCULATOR_H
#define INVESTMENTCALCULATOR_H

class InvestmentCalculator {
private:
    // variables for the investment information
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int numberOfYears;

    // helper functions used for input checking and display
    double getValidatedDouble(const char* prompt);
    int getValidatedInt(const char* prompt);
    void displayInputScreen() const;

public:
    // constructor
    InvestmentCalculator();

    // main functions for the program
    void run();
    void getUserInput();
    void displayReportWithoutMonthlyDeposit() const;
    void displayReportWithMonthlyDeposit() const;
};

#endif