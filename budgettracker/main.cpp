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
//I changed this 

using namespace std;

void addExpenses(vector<expenseItem> &budget);
void searchExpenseMenu(void);
void mainMenu(vector<expenseItem> &budget);

int main(int argc, const char * argv[]) {
    
    int userChoice;
    int itemNumber;
    string tempString;
    double tempDouble;
    
    vector<expenseItem> budget;
    
    cout << "Welcome to LLT's budget program." << endl << endl;
    
    cout << "Would you like to load the previous database or start fresh?" << endl;
    cout << "Enter 1 for load, 2 for fresh: ";
    
    cin >> userChoice;
    
    if(userChoice == 1) {
        ifstream infile;
        infile.open("savefile.txt");
        if (infile) {
            infile >> itemNumber;
            for (int counter = 0; counter < itemNumber; counter++)
            {
                expenseItem newExpense;
                budget.push_back(newExpense);
                getline(infile, tempString);
                cout << tempString;
                budget[counter].setObject(tempString);
                infile >> tempDouble;
                cout << tempDouble;
                budget[counter].setPrice(tempDouble);
            }
        }
    }
    
    cout << budget.size() << " records loaded." << endl;
    
    for (int counter=0; counter < budget.size(); counter++) {
        cout << budget[counter].getObject() << endl;
        cout << budget[counter].getPrice() << endl;
    }
    
    //boost::container::vector<expenseItem::expenseItem> budget(100);
    
    mainMenu(budget);
        
    ofstream savefile;
    savefile.open("savefile.txt");
    if (savefile) {
       // cout << "open" << endl;
        savefile << budget.size() << endl;
        for (int counter=0; counter < budget.size(); counter++) {
            savefile << budget[counter].getObject() << endl;
            savefile << budget[counter].getPrice() << endl;
        }
    }
    
    return 0;
}

void mainMenu(vector<expenseItem> &budget) {
    
    int userChoice;
    bool userDone;
    
    while(!userDone) {
        
        cout << "Enter the corresponding number to select your choice of action:" << endl << "1: Add New Expense" << endl << "2: Search Expenses" << endl << "3: Exit Program" << endl << endl << "Your choice: ";
        
        cin >> userChoice;
        
        while (userChoice < 1|| userChoice > 3) {
            cout << "Input invalid, please select again: " << endl;
            cin >> userChoice;
        }
        
        if (userChoice==1) {
            addExpenses(budget);
        }
        
        if (userChoice==2) {
            searchExpenseMenu();
        }
        
        if (userChoice==3) {
            userDone = true;
        }
    }
}

void addExpenses(vector<expenseItem> &budget) {
    
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
        
    budget.push_back(newItem);
    
}

void searchExpenseMenu(void) {
    

}

