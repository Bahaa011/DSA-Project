/*-- MenuItem.cpp -----------------------------------------------------------
   This file implements the member functions of the MenuItem class.
--------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "MenuItem.h"

//--- Definition of MenuItem constructor
MenuItem::MenuItem(int id, const string& name,
     const string& description, double price){
    setId(id);
    setName(name);
    setDescription(description);
    setPrice(price);
}

//--- Definition of getId()
int MenuItem::getId() const{
    return id;
}

//--- Definition of getName()
string MenuItem::getName() const{
    return name;
}

//--- Definition of getDescription()
string MenuItem::getDescription() const{
    return description;
}

//--- Definition of getPrice()
double MenuItem::getPrice() const{
    return price;
}

//--- Definition of setId()
void MenuItem::setId(int id){
    if (id < -1) {
        this->id = 0;
    }
    else {
        this->id = id;
    }
}

//--- Definition of setName()
void MenuItem::setName(const string& name){
    this->name = name;
}

//--- Definition of setDescription()
void MenuItem::setDescription(const string& description){
    this->description = description;
}

//--- Definition of setPrice()
void MenuItem::setPrice(double price){
    if (price <= 0.0){
        this->price = 0.99;
    }
    else{
        this->price = price;
    }
}

//--- Definition of operator<<
ostream& operator<<(ostream& out, const MenuItem& menuItem){
    out << "ID: " << menuItem.id << ", Name: " 
        << menuItem.name << ", Price: $" << menuItem.price << endl;
        
    return out;
}
