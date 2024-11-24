/*-- CompletedOrderStack.h -----------------------------------------------------

  This header file defines the CompletedOrderStack class, which represents 
  a stack of completed orders implemented using a singly linked list.

  Basic operations:
    Constructor:           Initializes an empty stack.
    Destructor:            Releases dynamically allocated memory for the stack.
    isEmpty:               Checks if the stack is empty.
    size:                  Returns the number of orders in the stack.
    getOrder:              Retrieves an order by index without modifying the stack.
    push:                  Adds a completed order to the top of the stack.
    pop:                   Removes and returns the top order from the stack.
    calculateTotalRevenue: Calculates the total revenue from all orders in the stack.
    display:               Outputs the contents of the stack to the console.
    saveToFile:            Saves the stack's contents to a file.
    Overloaded <<:         Outputs the entire stack to an output stream (defined 
                           outside the class).

  Class Invariant:
    1. The stack elements are stored in a singly linked list.
    2. The `top` pointer points to the most recently added node in the stack.
    3. If the stack is empty, the `top` pointer is null.
-----------------------------------------------------------------------------*/

#ifndef COMPLETEDORDERSTACK_H
#define COMPLETEDORDERSTACK_H

#include "Order.h"
#include <iostream>
#include <fstream>

using namespace std;

class CompletedOrderStack {
private:
    /***** Nested Node Class *****/
    class Node {
    public:
        Order data;  // The Order stored in this Node
        Node* next;  // Pointer to the next Node in the stack

        Node(const Order& data) : data(data), next(NULL) {}
        /*--------------------------------------------------------------------
          Construct a Node with the given Order.

          Precondition:  None.
          Postcondition: A Node is created with the specified Order, and the 
                         next pointer is initialized to NULL.
        --------------------------------------------------------------------*/
    };

    Node* top;  // Pointer to the top Node in the stack

public:
    typedef Node* NodePtr;

    /***** Constructor and Destructor *****/
    CompletedOrderStack();
    /*--------------------------------------------------------------------
      Construct an empty CompletedOrderStack.

      Precondition:  None.
      Postcondition: An empty CompletedOrderStack is initialized with `top`
                     set to NULL.
    --------------------------------------------------------------------*/

    ~CompletedOrderStack();
    /*--------------------------------------------------------------------
      Destructor: Releases dynamically allocated memory for the stack.

      Precondition:  None.
      Postcondition: All nodes in the stack are deleted, and memory is freed.
    --------------------------------------------------------------------*/

    /***** Stack Operations *****/
    bool isEmpty() const;
    /*--------------------------------------------------------------------
      Check if the stack is empty.

      Precondition:  None.
      Postcondition: Returns true if the stack is empty, false otherwise.
    --------------------------------------------------------------------*/

    int size() const;
    /*--------------------------------------------------------------------
      Calculate the number of elements in the stack.

      Precondition:  None.
      Postcondition: Returns the count of nodes in the stack.
    --------------------------------------------------------------------*/

    Order getOrder(int index) const;
    /*--------------------------------------------------------------------
      Retrieve an Order by its index without modifying the stack.

      Precondition:  0 <= index < size().
      Postcondition: Returns the Order at the specified index. Throws an 
                     exception if the index is out of bounds.
    --------------------------------------------------------------------*/

    void push(const Order& order);
    /*--------------------------------------------------------------------
      Add an Order to the top of the stack.

      Precondition:  None.
      Postcondition: The specified Order is added to the top of the stack.
    --------------------------------------------------------------------*/

    Order pop();
    /*--------------------------------------------------------------------
      Remove and return the Order at the top of the stack.

      Precondition:  The stack is not empty.
      Postcondition: The Order at the top of the stack is removed and returned.
                     Throws an exception if the stack is empty.
    --------------------------------------------------------------------*/

    double calculateTotalRevenue() const;
    /*--------------------------------------------------------------------
      Calculate the total revenue of all orders in the stack.

      Precondition:  None.
      Postcondition: Returns the sum of the total amounts for all Orders 
                     stored in the stack.
    --------------------------------------------------------------------*/

    void display() const;
    /*--------------------------------------------------------------------
      Display the contents of the stack.

      Precondition:  None.
      Postcondition: Outputs all Orders in the stack to the console, starting
                     from the top.
    --------------------------------------------------------------------*/

    void saveToFile(const string& filename) const;
    /*--------------------------------------------------------------------
      Save the stack's contents to a file.

      Precondition:  The file specified by `filename` is writable.
      Postcondition: All Orders in the stack are written to the file, starting
                     from the top.
    --------------------------------------------------------------------*/
};

/***** Overloaded Operators *****/
ostream& operator<<(ostream& out, const CompletedOrderStack& completedOrderStack);
/*--------------------------------------------------------------------
  Overload the << operator to output the CompletedOrderStack's contents.

  Precondition:  ostream out is open.
  Postcondition: Outputs all Orders in the stack to the stream, starting
                 from the top.
--------------------------------------------------------------------*/

#endif // COMPLETEDORDERSTACK_H
