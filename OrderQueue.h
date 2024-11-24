/*-- OrderQueue.h ------------------------------------------------------------

  This header file defines the OrderQueue class, which represents a queue of 
  Order objects implemented using a singly linked list.

  Basic operations:
    Constructor:       Initializes an empty queue.
    Destructor:        Releases dynamically allocated memory for the queue.
    isEmpty:           Checks if the queue is empty.
    enqueue:           Adds an Order to the rear of the queue.
    dequeue:           Removes and returns the Order at the front of the queue.
    deleteOrder:       Deletes an Order by its order ID from the queue.
    display:           Outputs the contents of the queue.
    Overloaded <<:     Outputs the entire queue to an output stream (defined 
                       outside the class).

  Class Invariant:
    1. The queue elements are stored in a singly linked list.
    2. The `front` pointer points to the first node in the queue.
    3. The `rear` pointer points to the last node in the queue.
    4. If the queue is empty, both `front` and `rear` are null.
-----------------------------------------------------------------------------*/

#ifndef ORDERQUEUE_H
#define ORDERQUEUE_H

#include "Order.h"
#include <iostream>

using namespace std;

class OrderQueue {
private:
    /***** Nested Node Class *****/
    class Node {
    public:
        Order data;  // The Order stored in this Node
        Node* next;  // Pointer to the next Node in the queue

        Node(const Order& data) : data(data), next(NULL) {};
        /*--------------------------------------------------------------------
          Construct a Node with the given Order.

          Precondition:  None.
          Postcondition: A Node is created with the specified Order and the 
                         next pointer initialized to NULL.
        --------------------------------------------------------------------*/
    };

    Node* front;  // Pointer to the first Node in the queue
    Node* rear;   // Pointer to the last Node in the queue

public:
    typedef Node* NodePtr;

    /***** Constructor and Destructor *****/
    OrderQueue();
    /*--------------------------------------------------------------------
      Construct an empty OrderQueue.

      Precondition:  None.
      Postcondition: An empty OrderQueue is initialized with `front` and
                     `rear` set to NULL.
    --------------------------------------------------------------------*/

    ~OrderQueue();
    /*--------------------------------------------------------------------
      Destructor: Releases dynamically allocated memory for the queue.

      Precondition:  None.
      Postcondition: All nodes in the queue are deleted, and memory is freed.
    --------------------------------------------------------------------*/

    /***** Queue Operations *****/
    bool isEmpty() const;
    /*--------------------------------------------------------------------
      Check if the queue is empty.

      Precondition:  None.
      Postcondition: Returns true if the queue is empty, false otherwise.
    --------------------------------------------------------------------*/

    void enqueue(const Order& order);
    /*--------------------------------------------------------------------
      Add an Order to the rear of the queue.

      Precondition:  None.
      Postcondition: The specified Order is added to the rear of the queue.
    --------------------------------------------------------------------*/

    Order dequeue();
    /*--------------------------------------------------------------------
      Remove and return the Order at the front of the queue.

      Precondition:  The queue is not empty.
      Postcondition: The Order at the front of the queue is removed and 
                     returned. Throws an exception if the queue is empty.
    --------------------------------------------------------------------*/

    bool deleteOrder(int orderId);
    /*--------------------------------------------------------------------
      Delete an Order by its ID from the queue.

      Precondition:  None.
      Postcondition: If an Order with the specified ID exists, it is removed
                     from the queue. Returns true if successful, false otherwise.
    --------------------------------------------------------------------*/

    void display() const;
    /*--------------------------------------------------------------------
      Display the contents of the queue.

      Precondition:  None.
      Postcondition: Outputs all Orders in the queue to the console, starting
                     from the front.
    --------------------------------------------------------------------*/
};

/***** Overloaded Operators *****/
ostream& operator<<(ostream& out, const OrderQueue& orderQueue);
/*--------------------------------------------------------------------
  Overload the << operator to output the OrderQueue's contents.

  Precondition:  ostream out is open.
  Postcondition: Outputs all Orders in the queue to the stream, starting
                 from the front.
--------------------------------------------------------------------*/

#endif // ORDERQUEUE_H
