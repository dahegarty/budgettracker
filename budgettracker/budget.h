//
//  budget.h
//  budgettracker
//
//  Created by Andrew van Tonningen on 4/29/16.
//  Copyright © 2016 Landward Lemon Technologies. All rights reserved.
//

#ifndef budget_h
#define budget_h

#include "expenseItem.h"

using namespace std;

class Budget {
    
    string budgetName;//name of budget input by user
    string fileName;//filename of budget for permanent storage
    
public:
    
    vector<expenseItem> expenseVector;//data structure to hold budget items
    vector<Budget> budgetVector;
    int numBudgets;
    
    
    expenseItem getItem(int i){
        return expenseVector[i];
    }
    void insertItem(expenseItem c){
        expenseVector.push_back(c);
    }
    
    int budgetSize(){
        return expenseVector.size();
    }
    
    
    string getName(){
        return budgetName;
    }
    void setName(string s){
        budgetName = s;
    }
    
    string getFileName(){
        return fileName;
    }
    void setFileName(string s){
        fileName = s;
    }
    void setVector(vector<expenseItem> itemList) {
        expenseVector = itemList;
    }
    
    
    
};


#endif /* budget_h */
