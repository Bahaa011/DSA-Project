/*-- CompletedOrderStack.cpp --------------------------------------------------
              This file implements CompletedOrderStack member functions.
--------------------------------------------------------------------------
*/

#include "CompletedOrderStack.h"

//--- Definition of CompletedOrderStack constructor
CompletedOrderStack::CompletedOrderStack(){
    top = NULL;
}

//--- Definition of CompletedOrderStack destructor
CompletedOrderStack::~CompletedOrderStack(){
    NodePtr current = top;
    NodePtr nextNode;

    // Iterate through the stack and delete each node
    while (current != NULL) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }

    top = NULL;
}

//--- Definition of isEmpty()
bool CompletedOrderStack::isEmpty() const {
    return top == NULL;
}

//--- Definition of size()
int CompletedOrderStack::size() const {
    int size = 0;
    NodePtr current = top;  // Start from the top of the stack
    while (current != NULL) {
        size++;  // Increment size for each node
        current = current->next;  // Move to the next node
    }
    return size;
}

//--- Definition of getOrder()
Order CompletedOrderStack::getOrder(int index) const {
    int currentIndex = 0;
    NodePtr current = top;
    while (current != NULL) {
        if (currentIndex == index) {
            return current->data;  // Return the order at the specified index
        }
        currentIndex++;
        current = current->next;
    }
    return Order();  // Return a default Order if index is out of bounds
}

//--- Definition of push()
void CompletedOrderStack::push(const Order& order){
    NodePtr newNode = new(nothrow) Node(order);
    
    if(!newNode){
        cerr << "Memory Allocation Failed" << endl;
        return;
    }
    
    newNode->next = top;
    top = newNode;
}

//--- Definition of pop()
Order CompletedOrderStack::pop(){
    if(isEmpty()){
        return Order();
    }
    
    NodePtr temp = top;
    top = top->next;
    Order data = temp->data;
    delete temp;
    return data;
}

//--- Definition of calculateTotalRevenue()
double CompletedOrderStack::calculateTotalRevenue() const {    
    double total = 0;
    NodePtr current = top;
    
    // Iterate through the stack and calculate the total
    while(current != NULL){
        total += current->data.calculateTotalAmount();
        current = current->next;
    }
    
    return total;
}

//--- Definition of saveToFile()
void CompletedOrderStack::saveToFile(const string& filename) const {
    ofstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }
    
    // Traverse the stack and write each order's details
    Node* current = top;

    while (current != nullptr) {
        const Order& order = current->data; // Access the order stored in the node

        // Write Order ID and Customer Name
        file << order.getOrderId() << "," << order.getCustomerName() << ",";

        // Write items name and price seperated by colon and encased in quotes
        file << "\"";
        for (int i = 0; i < order.getItemCount(); ++i) { 
            const MenuItem& item = order.getItem(i);
            file << item.getName() << ":" << item.getPrice();
            if (i < order.getItemCount() - 1) {
                file << "&"; // Separate items with a ampersand
            }
        }
        file << "\","; // Close quotes

        // Write total price
        file << order.calculateTotalAmount() << endl;

        // Move to the next node
        current = current->next;
    }

    // Write total revenue of all orders
    file << "Total revenue is: $" << calculateTotalRevenue() << endl;
    
    file.close(); // Close the file
}

//--- Definition of display()
void CompletedOrderStack::display() const {
    cout << "--- Completed Orders ---" << endl;
    
    if(isEmpty()){
        cout << "No completed orders" << endl << endl;
        return;
    }
    
    // Iterate through the stack and display every completed order
    NodePtr current = top;
    while(current != NULL){
        cout << current->data;
        current = current->next;
    }
}

//--- Definition of overloaded operator<<()
ostream& operator<<(ostream& out, const CompletedOrderStack& completedOrderStack){
    completedOrderStack.display();
    return out;
}
