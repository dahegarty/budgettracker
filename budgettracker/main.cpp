//
//  main.cpp
//  budgettracker
//
//  Created by Andrew van Tonningen on 2/18/16.
//  Copyright © 2016 Landward Lemon Technologies. All rights reserved.
//

#include <iostream>

using namespace std;

void addExpenseMenu(void);
void searchExpenseMenu(void);
void mainMenu(void);

int main(int argc, const char * argv[]) {
    
    cout << "Welcome to LLT's budget program." << endl << endl;
    
    mainMenu();
    
    return 0;
}

void mainMenu(void) {
    
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
            addExpenseMenu();
        }
        
        if (userChoice==2) {
            searchExpenseMenu();
        }
        
        if (userChoice==3) {
            userDone = true;
        }
    }
}

void addExpenseMenu(void) {
    
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
