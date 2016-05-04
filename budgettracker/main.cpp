//
//  main.cpp
//  budgettracker
//
//  Created by Andrew van Tonningen on 2/18/16.
//  Copyright © 2016 Landward Lemon Technologies. All rights reserved.
//

#include <iostream>
//#include "vector.hpp"
#include "expenseItem.h"
#include <string>
#include <vector>
#include <fstream>
#include "budget.h"
//I changed this 
//I changed this too

//int numberOfBudgets = 0;
//vector<Budget> vectorOfBudgets;

using namespace std;

void addExpenses(Budget &workingBudget);
void searchExpenseMenu(void);
void BudgetMenu(Budget workingBudget);
void save(Budget &workingBudget);
void viewRecords(Budget &workingBudget);

int main(int argc, const char * argv[]) {
    
    int userChoice;
    int itemNumber;
    string tempString;
    double tempDouble;
    string dumpString;
    
    int numBudgets = 0;
    string budgetChoice;
    
    vector<Budget> budgetVector;
    Budget workingBudget;
    vector<expenseItem> itemVector;
    
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
        //vectorOfBudgets = budgetVector;
        //numberOfBudgets = numBudgets;
    }
    
    if (numBudgets > 0) {
    
        cout << "Would you like to load a database or start fresh?" << endl;
        cout << "Enter 1 for load, 2 for new database: ";
    
        cin >> userChoice;
        
        if(userChoice == 1) {
            cout << "Please select a budget to load: " << endl;
            
            for (int counter = 0; counter < numBudgets; counter++) {
                cout << budgetVector[counter].getName() << endl;
            }
            
            cin >> budgetChoice;
            
            ifstream infile;
            infile.open(budgetChoice + ".txt");
            if (infile) {
                infile >> itemNumber;
                for (int counter = 0; counter < itemNumber; counter++)
                {
                    getline(infile, dumpString);
                    expenseItem newExpense;
                    itemVector.push_back(newExpense);
                    getline(infile, tempString);
                    //cout << tempString << endl;
                    itemVector[counter].setObject(tempString);
                    infile >> tempDouble;
                    //cout << tempDouble << endl;
                    itemVector[counter].setPrice(tempDouble);
                }
            }
            
            cout << itemVector.size() << " records loaded." << endl;
            
            for (int counter=0; counter < itemVector.size(); counter++) {
                cout << itemVector[counter].getObject() << endl;
                cout << itemVector[counter].getPrice() << endl;
            }

        }
        
        if (userChoice == 2) {
            cout << "Enter a name for your new database: " << endl;
            cin >> tempString;
            Budget newBudget;
            newBudget.setName(tempString);
            workingBudget = newBudget;
            numBudgets++;
            budgetVector.push_back(newBudget);
            
            ofstream budgetfile;
            budgetfile.open("budgetfile.txt");
            if (budgetfile) {
                // cout << "open" << endl;
                budgetfile << numBudgets << endl;
                for (int counter = 0; counter < numBudgets; counter++) {
                    budgetfile << budgetVector[counter].getName() << endl;
                }
            }
        
        }
        
        workingBudget.setName(budgetChoice);
        workingBudget.setVector(itemVector);
        workingBudget.budgetVector = budgetVector;
        workingBudget.numBudgets = numBudgets;
    }
    
    else {
        
        cout << "No existing budgets found.  Please create one now." << endl;
        cout << "Enter a name for your new database: " << endl;
        cin >> tempString;
        Budget newBudget;
        newBudget.setName(tempString);
        workingBudget = newBudget;
        
        numBudgets++;
        budgetVector.push_back(newBudget);
        
        ofstream budgetfile;
        budgetfile.open("budgetfile.txt");
        if (budgetfile) {
            // cout << "open" << endl;
            budgetfile << numBudgets << endl;
            for (int counter = 0; counter < numBudgets; counter++) {
                budgetfile << budgetVector[counter].getName() << endl;
            }
        }
        
        workingBudget.budgetVector = budgetVector;
        
    }
    
    //boost::container::vector<expenseItem::expenseItem> budget(100);
    
    BudgetMenu(workingBudget);
    
    return 0;
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
            save(workingBudget);
            userDone = true;
        }
        
        if (userChoice==4) {
            userDone = true;
        }
    }
}

void viewRecords(Budget &workingBudget) {
    cout << "NumRecords: " << workingBudget.expenseVector.size() << endl;
    for (int counter = 0; counter < workingBudget.expenseVector.size(); counter++) {
        //cout << counter << endl;
        cout << workingBudget.expenseVector[counter].getObject() << endl;
        cout << workingBudget.expenseVector[counter].getPrice() << endl;
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

void save(Budget &workingBudget) {
    
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

void searchExpenseMenu(void) {
    

}

