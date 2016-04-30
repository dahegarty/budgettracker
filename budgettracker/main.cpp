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
//I changed this too

using namespace std;

void addExpenseMenu(vector<expenseItem> &budget);
void searchExpenseMenu(void);
void mainMenu(vector<expenseItem> &budget);

int main(int argc, const char * argv[]) {
    
    cout << "Welcome to LLT's budget program." << endl << endl;
    
    //boost::container::vector<expenseItem::expenseItem> budget(100);
    
    vector<expenseItem> budget;
    
    mainMenu(budget);
    
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
            addExpenseMenu(budget);
        }
        
        if (userChoice==2) {
            searchExpenseMenu();
        }
        
        if (userChoice==3) {
            userDone = true;
        }
    }
}

void addExpenseMenu(vector<expenseItem> &budget) {
    
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
    
   /* int userChoice;
    bool userDone;
    
    while(!userDone) {
        
        cout << "Enter the corresponding number to select your choice of action:" << endl << "1: Add New Expense" << endl << "2: Search Expenses" << endl << "3: Exit Program" << endl << endl << "Your choice: ";
        
        cin >> userChoice;
        
        while (userChoice < 1|| userChoice > 3) {
            cout << "Input invalid, please select again: " << endl;
            cin >> userChoice;
        }
        
        if (userChoice==1) {
            addExpenseMenu();
        }
        
        if (userChoice==2) {
            searchExpenseMenu();
        }
        
        if (userChoice==3) {
            userDone = true;
        }
    } */
}

void addExpense(void) {
    
    
    
}
