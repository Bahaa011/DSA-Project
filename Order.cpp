/*-- Order.cpp --------------------------------------------------------------
              This file implements Order member functions.
--------------------------------------------------------------------------*/

#include "Order.h"

//--- Definition of Order constructor
Order::Order(int id, const string& customerName){
    setOrderId(id);
    setCustomerName(customerName);
    size = 0;
    capacity = 10;
    items = new MenuItem[capacity];
    status = 'P';
}

//--- Definition of Order copy constructor
Order::Order(const Order& other) {
    orderId = other.orderId;
    customerName = other.customerName;
    size = other.size;
    capacity = other.capacity;
    status = other.status;

    // Allocate new memory for the items array
    items = new MenuItem[capacity];
    for (int i = 0; i < size; i++) {
        items[i] = other.items[i]; // Copy each item
    }
}

//--- Definition of Order destructor
Order::~Order(){
    delete [] items;
}

//--- Definition of resize()
void Order::resize(){
    // Allocate new memory and copy items
    MenuItem* newArray = new MenuItem[capacity*2];
    for(int i = 0; i < size; i++){
        newArray[i] = items[i]; // Copy each item
    }
    
    capacity *= 2;
    delete [] items;
    items = newArray;
}

//--- Definition of isEmpty()
bool Order::isEmpty() const {
    return size == 0;
}

//--- Definition of getOrderId()
int Order::getOrderId() const {
    return orderId;
}

//--- Definition of getCustomerName()
string Order::getCustomerName() const {
    return customerName;
}

//--- Definition of getStatus()
char Order::getStatus() const {
    return status;
}

//--- Definition of getItemCount()
int Order::getItemCount() const {
    return size;
}

//--- Definition of getItem()
MenuItem Order::getItem(int i) const {
    if (i < 0 || i >= size) {
        MenuItem garbage;
        return garbage;
    }
    return items[i];
}

//--- Definition of setOrderId()
void Order::setOrderId(int id){
    if(id < 0){
        orderId = 0;
    } else {
        orderId = id;
    }
}

//--- Definition of setCustomerName()
void Order::setCustomerName(const string& customerName){
    this->customerName = customerName;
}

//--- Definition of setStatus()
void Order::setStatus(char status){
    if(status == 'P' || status == 'p'){
        this->status = 'P';
    } else if (status == 'C' || status == 'c'){
        this->status = 'C';
    } else {
        this->status = 'P';
    }
}

//--- Definition of addItem()
void Order::addItem(const MenuItem& item){
    if(size == capacity)
        resize();
    
    items[size] = item;
    size++;
}

//--- Definition of calculateTotalAmount()
double Order::calculateTotalAmount() const {
    double total = 0;
    
    for(int i = 0; i < size; i++){
        total += items[i].getPrice();
    }
    
    return total;
}

//--- Definition of assignment operator=()
Order& Order::operator=(const Order& other) {
    if (this != &other) {  // Avoid self-assignment
        // Free existing resources
        delete[] items;

        // Copy data from the other object
        orderId = other.orderId;
        customerName = other.customerName;
        size = other.size;
        capacity = other.capacity;
        status = other.status;

        // Allocate new memory and copy items
        items = new MenuItem[capacity];
        for (int i = 0; i < size; i++) {
            items[i] = other.items[i];
        }
    }

    return *this;
}

//--- Definition of overloaded operator<<()
ostream& operator<<(ostream& out, const Order& order){
    out << "Order ID: " << order.orderId << ", Customer: " 
        << order.customerName << endl 
        << "Items: " << endl;

    for (int i = 0; i < order.size; i++) {
        out << "  - " << order.items[i].getName() << " ($" 
            << order.items[i].getPrice() << ")" << endl;
    }

    out << "Status: " 
        << (order.status == 'P' ? "Pending" : 
           (order.status == 'C' ? "Completed" : "Unknown")) 
        << endl << endl;

    return out;
}
