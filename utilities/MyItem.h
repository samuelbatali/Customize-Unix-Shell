//
//  MyItem.h
//  MyPlanner
//
//  Created by Sam Batali on 3/2/18.
//  Copyright © 2018 Dariokwo. All rights reserved.
//

#pragma once

#include<iostream>

using std::string; 
using std::ostream;

// creating MyItem object which contains name,price,and number
struct MyItem
{
    //   public MyItem variables
    string m_name;
    string m_type;
    double m_price;
    
    //   constructors (overloaded)
    MyItem() : m_name(), m_type(), m_price(0.0) {}
    MyItem(string name, string type = "", double price = 0.0) : m_name(name), m_type(type), m_price(price) {}
    
    // IMPLEMENTING THE RULE OF THREE BELOW

    //  Copy Constructor
    MyItem(const MyItem& item)
    {
        m_name = item.m_name;
        m_type = item.m_type;
        m_price = item.m_price;
    }
    // Assignment operator
    MyItem& operator=(const MyItem& item)
    {
        m_name = item.m_name;
        m_type = item.m_type;
        m_price = item.m_price;
        
        return *this;
    }

    // Use Default Destructor because there's no heap allaocation
    // ~MyItem(); 

    // GETTERS AND SETTERS ARE NOT REALLY NECESSARY FOR THIS EXAMPLE
    // BECAUSE ALL PROPERTIES ARE PUBLIC FOR THIS STRUCT
    
    //   Setters
    void setName(const string& name)
    {
        m_name = name;
    }
    void setType(const string& type)
    {
        m_type = type;
    }
    void setPrice(const double& price)
    {
        m_price = price;
    }

    // Getters
    string getName() { return m_name; }
    string getType() { return m_type; }
    double getPrice() { return m_price; }

    // public method updates the price propert
    void updatePrice(double price)
    {
        m_price += price;
    }
    
    // Overloading output stream (<<) to make MyItem object printable
    // Very helpful in debugging
    friend ostream& operator<<(ostream& out, MyItem item)
    {
        out << "Name: " << item.m_name << ", ";
        out << "Type: " << item.m_type << ", ";
        out << "Price: " << item.m_price;
        return out;
    }
};
