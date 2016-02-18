//
//  expenseItem.h
//  budgettracker
//
//  Created by Domnall Hegarty on 2/18/16.
//  Copyright © 2016 Landward Lemon Technologies. All rights reserved.
//
#ifndef expenseItem_h
#define expenseItem_h
#include <string>


class expenseItem{

    //date
    string date;
    
    //price
    double price;
    
    //category
    enum expenseCategory{
        food = 1,
        bills = 2,
        personal = 3
    }
    expenseCategory category;
    
    //object purchased
    string object;
    
    //vendor
    string vendor;
    
private:
    void setDate(string d){
        date = d;
    }
    
    string getDate(){
        return date;
    }
    
    void setPrice(double p){
        price = p;
    }
    
    double getPrice(){
        return price;
    }
    
    void setCategory(expenseCategory c){
        category = c;
    }
    void getCategory(){
        return category;
    }
    void setObject(string o){
        object = o;
    }
    
    string getObject(){
        return object;
    }
    
    void setVendor(string v){
        vendor = v;
    }
    
    string getVendor(){
        return vendor;
    }


    
    
};


#endif /* expenseItem_h */
