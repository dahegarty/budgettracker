//
//  main.cpp
//  budgettracker
//
//  Created by Andrew van Tonningen on 2/18/16.
//  Copyright © 2016 Landward Lemon Technologies. All rights reserved.
//

#include <iostream>
#include "expenseItem.h"
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "budget.h"
#include <cmath>

using namespace std;

void addExpenses(Budget &);
void BudgetMenu(Budget);
void writeToExpenseDB(Budget &);
void viewRecords(Budget &);
void loadBudget(Budget &, vector<Budget>);
void createBudget(Budget &, vector<Budget>);
void writeToBudgetDB(vector<Budget>);

int main(int argc, const char * argv[]) {
    
    int userChoice;
    string tempString;
    string dumpString;
    
    int numBudgets = 0;
    string budgetChoice;
    
    vector<Budget> budgetVector;
    Budget workingBudget;
    
    cout << "Welcome to LLT's budget program." << endl << endl;
    
    
    ifstream budgetfile;
    budgetfile.open("budgetfile.txt");
    
    if (budgetfile) {
        budgetfile >> numBudgets;
        getline(budgetfile, dumpString);
        for (int counter = 0; counter < numBudgets; counter ++) {
            getline(budgetfile, tempString);
            Budget newBudget;
            newBudget.setName(tempString);
            budgetVector.push_back(newBudget);
        }
    }
    
    if (numBudgets > 0) {
    
        cout << "Would you like to load a database or start fresh?" << endl;
        cout << "Enter 1 for load, 2 for new database: ";
    
        cin >> userChoice;
        
        if(userChoice == 1) {
            
            loadBudget(workingBudget, budgetVector);
            
        }
        
        if (userChoice == 2) {
            
            createBudget(workingBudget, budgetVector);
            
        }
    }
    
    else {
        
        cout << "No existing budgets found.  Please create one now." << endl;
        
        createBudget(workingBudget, budgetVector);
        
    }
    
    BudgetMenu(workingBudget);
    
    return 0;
}

void loadBudget(Budget &workingBudget, vector<Budget> budgetVector) {
    
    int numExpenses;
    string budgetChoice;
    
    string dumpString;
    string tempString;
    double tempDouble;
    
    cout << endl << "Please select a budget to load: " << endl << endl;
    
    for (int counter = 0; counter < budgetVector.size(); counter++) {
        cout << budgetVector[counter].getName() << endl;
    }
    cout << endl;
    
    cin >> budgetChoice;
    
    ifstream infile;
    infile.open(budgetChoice + ".txt");
    if (infile) {
        infile >> numExpenses;
        for (int counter = 0; counter < numExpenses; counter++)
        {
            getline(infile, dumpString);
            expenseItem newExpense;
            workingBudget.expenseVector.push_back(newExpense);
            getline(infile, tempString);
            //cout << tempString << endl;
            workingBudget.expenseVector[counter].setObject(tempString);
            infile >> tempDouble;
            //cout << tempDouble << endl;
            workingBudget.expenseVector[counter].setPrice(tempDouble);
        }
    }
    
    workingBudget.setName(budgetChoice);
    workingBudget.budgetVector = budgetVector;
    
    viewRecords(workingBudget);
    
}

void writeToBudgetDB(vector<Budget> budgetVector) {
    
    ofstream budgetfile;
    budgetfile.open("budgetfile.txt");
    if (budgetfile) {
        cout << "open" << endl;
        budgetfile << budgetVector.size() << endl;
        for (int counter = 0; counter < budgetVector.size(); counter++) {
            budgetfile << budgetVector[counter].getName() << endl;
        }
    }

}

void createBudget(Budget &workingBudget, vector<Budget> budgetVector) {
    
    string tempString;
    
    cout << "Enter a name for your new database: " << endl;
    cin >> tempString;
    Budget newBudget;
    newBudget.setName(tempString);
    workingBudget = newBudget;
    budgetVector.push_back(newBudget);
    
    workingBudget.budgetVector = budgetVector;
    
    writeToBudgetDB(workingBudget.budgetVector);
    
}


void BudgetMenu(Budget workingBudget) {
    
    int userChoice;
    bool userDone = false;
    
    while(!userDone) {
        
        cout << "Enter the corresponding number to select your choice of action:" << endl << "1: Add New Expense" << endl << "2: View Expenses" << endl << "3: Save & Exit" << endl << "4: Exit Without Saving" << endl << "Your choice: ";
        
        cin >> userChoice;
        
        while (userChoice < 1|| userChoice > 4) {
            cout << "Input invalid, please select again: " << endl;
            cin >> userChoice;
        }
        
        if (userChoice==1) {
            addExpenses(workingBudget);
        }
        
        if (userChoice==2) {
           viewRecords(workingBudget);
        }
        
        if (userChoice==3) {
            writeToExpenseDB(workingBudget);
            userDone = true;
        }
        
        if (userChoice==4) {
            userDone = true;
        }
    }
}

void viewRecords(Budget &workingBudget) {
    
    cout << endl << workingBudget.expenseVector.size() << " record(s) in " << workingBudget.getName() << endl << endl;
    
    for (int counter=0; counter < workingBudget.expenseVector.size(); counter++) {
        cout << "Expense " << counter+1 << ":" << endl;
        cout << "Item: " << workingBudget.expenseVector[counter].getObject() << endl;
        if (workingBudget.expenseVector[counter].getPrice() < 0) {
            cout << "Cost: -$" << setprecision(2)  << fixed << abs(workingBudget.expenseVector[counter].getPrice()) << endl;
        }
        else {
        cout << "Cost: $" << setprecision(2) << fixed << workingBudget.expenseVector[counter].getPrice() << endl;
        }
        cout << endl;
    }
}

void addExpenses(Budget &workingBudget) {
    
    //int tempInt;
    string tempString;
    double tempDouble;
        
    expenseItem newItem;
        
    cout << "Enter a description of the expense: ";
    cin >> tempString;
    newItem.setObject(tempString);
        
    cout << "Enter the price of the expense: ";
    cin >> tempDouble;
    newItem.setPrice(tempDouble);
        
    workingBudget.expenseVector.push_back(newItem);
    
}

void writeToExpenseDB(Budget &workingBudget) {
    
    ofstream savefile;
    savefile.open(workingBudget.getName()+".txt");
    if (savefile) {
        cout << "open" << endl;
        savefile << workingBudget.expenseVector.size() << endl;
        for (int counter=0; counter < workingBudget.expenseVector.size(); counter++) {
            savefile << workingBudget.expenseVector[counter].getObject() << endl;
            savefile << workingBudget.expenseVector[counter].getPrice() << endl;
        }
    }
}

