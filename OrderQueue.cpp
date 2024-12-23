/*-- OrderQueue.cpp -----------------------------------------------------------
              This file implements OrderQueue member functions.
--------------------------------------------------------------------------*/

#include "OrderQueue.h"

//--- Definition of OrderQueue constructor
OrderQueue::OrderQueue(){
    front = NULL;
    rear = NULL;
}

//--- Definition of OrderQueue destructor
OrderQueue::~OrderQueue(){
    NodePtr current = front;
    NodePtr nextNode;

    // Iterate through the queue and delete each node
    while (current != NULL) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }

    front = NULL;
    rear = NULL; 
}

//--- Definition of isEmpty()
bool OrderQueue::isEmpty() const {
    return front == NULL;
}

//--- Definition of enqueue()
void OrderQueue::enqueue(const Order& order){
    NodePtr newNode = new(nothrow) Node(order);
    
    if(!newNode){
        cerr << "Memory Allocation Failed" << endl;
        return;
    }

    if(isEmpty()){
        front = newNode;
        rear = front;
        return;
    }
    
    rear->next = newNode;
    rear = newNode;
}

//--- Definition of dequeue()
Order OrderQueue::dequeue() {
    if (isEmpty()) {
        cerr << "Queue is empty!" << endl;
        return Order();
    }
    
    NodePtr temp = front;
    front = front->next;
    
    if(front == NULL)
        rear = NULL;
    
    Order order = temp->data;
    order.setStatus('C');
    
    delete temp;
    return order;
}

//--- Definition of deleteOrder()
bool OrderQueue::deleteOrder(int orderId){
    if(isEmpty()){
        return false;
    }
    
    if (front->data.getOrderId() == orderId) {
        NodePtr temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;  // Free the memory of the deleted node
        return true;
    }
    
    NodePtr current = front;
    while(current->next != NULL){
        if(current->next->data.getOrderId() == orderId){
            NodePtr temp = current->next;
            current->next = current->next->next;

            if (current->next == NULL) {
                rear = current;
            }

            delete temp; // Free the memory of the deleted node
            return true;
        }
        
        current = current->next;
    }
    return false;
}

//--- Definition of display()
void OrderQueue::display() const {
    cout << "--- Active Orders ---" << endl;
    
    if(isEmpty()){
        cout << "No active orders" << endl << endl;
        return;
    }
    
    // Iterate through the queue displaying each order
    NodePtr current = front;
    while(current != NULL){
        cout << current->data;
        current = current->next;
    }
}

//--- Definition of overloaded operator<<()
ostream& operator<<(ostream& out, const OrderQueue& orderQueue){
    orderQueue.display();
    return out;
}
