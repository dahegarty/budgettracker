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
    vector<expenseItem> budget;//data structure to hold budget items
    string budgetName;//name of budget input by user
    string fileName;//filename of budget for permanent storage
public:
    expenseItem getItem(int i){
        return budget[i];
    }
    void insertItem(expenseItem c){
        budget.push_back(c);
    }
    
    int budgetSize(){
        return budget.size();
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
    
    
    
};


#endif /* budget_h */
