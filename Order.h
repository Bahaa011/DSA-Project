/*-- Order.h -----------------------------------------------------------------

  This header file defines the Order class, which represents a customer's order.
  An Order consists of a unique ID, customer name, a dynamic list of MenuItems, 
  the order's status, and methods for managing the order's items and details.
  
  Basic operations:
    Constructor:         Constructs an Order with default or specified values.
    Destructor:          Releases dynamically allocated memory.
    Copy constructor:    Creates a deep copy of an Order object.
    Assignment operator: Assigns the values of one Order to another.
    Accessors:           Retrieve order attributes (ID, customer name, status, items).
    Mutators:            Modify order attributes (ID, customer name, status).
    Item management:     Add items to the order, retrieve items, check item count.
    Calculate total:     Compute the total cost of all items in the order.
    Overloaded <<:       Outputs the Order details to an output stream.

  Class Invariant:
    1. The order ID is a unique positive integer.
    2. Customer name is a non-empty string.
    3. Status is a valid character representing the order state 
       (e.g., 'P' for pending, 'C' for completed).
    4. Items are stored in a dynamically allocated array, resized as needed.
-----------------------------------------------------------------------------*/

#ifndef ORDER_H
#define ORDER_H

using namespace std;

#include "MenuItem.h"
#include <cassert>

class Order {
public:
    /***** Constructors and Destructor *****/
    Order(int id = 0, const string& customerName = "");
    /*------------------------------------------------------------------------
      Construct an Order object with default or specified values.

      Precondition:  None.
      Postcondition: Order is initialized with the specified ID and customer 
                     name, or default values if not provided. Items array 
                     is initialized with default capacity.
    ------------------------------------------------------------------------*/

    Order(const Order& other);
    /*------------------------------------------------------------------------
      Copy constructor: Create a deep copy of another Order object.

      Precondition:  None.
      Postcondition: A new Order is created with the same values and 
                     dynamically allocated memory as the original.
    ------------------------------------------------------------------------*/

    ~Order();
    /*------------------------------------------------------------------------
      Destructor: Releases dynamically allocated memory for the items array.

      Precondition:  None.
      Postcondition: The memory for the items array is deallocated.
    ------------------------------------------------------------------------*/

    /***** Accessor Functions *****/
    bool isEmpty() const;
    /*------------------------------------------------------------------------
      Check if the order contains any items.

      Precondition:  None.
      Postcondition: Returns true if the order has no items, false otherwise.
    ------------------------------------------------------------------------*/

    int getOrderId() const;
    /*------------------------------------------------------------------------
      Retrieve the order ID.

      Precondition:  None.
      Postcondition: Returns the unique ID of the order.
    ------------------------------------------------------------------------*/

    string getCustomerName() const;
    /*------------------------------------------------------------------------
      Retrieve the customer name.

      Precondition:  None.
      Postcondition: Returns the name of the customer who placed the order.
    ------------------------------------------------------------------------*/

    char getStatus() const;
    /*------------------------------------------------------------------------
      Retrieve the order status.

      Precondition:  None.
      Postcondition: Returns the current status of the order.
    ------------------------------------------------------------------------*/

    int getItemCount() const;
    /*------------------------------------------------------------------------
      Retrieve the number of items in the order.

      Precondition:  None.
      Postcondition: Returns the number of items in the order.
    ------------------------------------------------------------------------*/

    MenuItem getItem(int i) const;
    /*------------------------------------------------------------------------
      Retrieve a specific item from the order.

      Precondition:  0 <= i < size.
      Postcondition: Returns the MenuItem at index i.
    ------------------------------------------------------------------------*/

    /***** Mutator Functions *****/
    void setOrderId(int id);
    /*------------------------------------------------------------------------
      Set the order ID.

      Precondition:  ID must be a unique positive integer.
      Postcondition: Updates the order's ID to the specified value.
    ------------------------------------------------------------------------*/

    void setCustomerName(const string& customerName);
    /*------------------------------------------------------------------------
      Set the customer name.

      Precondition:  Customer name must be a string.
      Postcondition: Updates the order's customer name.
    ------------------------------------------------------------------------*/

    void setStatus(char status);
    /*------------------------------------------------------------------------
      Set the status of the order.

      Precondition:  Status must be a valid character ('P', 'C', etc.).
      Postcondition: Updates the order's status to the specified value.
    ------------------------------------------------------------------------*/

    /***** Item Management *****/
    void addItem(const MenuItem& item);
    /*------------------------------------------------------------------------
      Add an item to the order.

      Precondition:  None.
      Postcondition: Adds the specified MenuItem to the order. Resizes the 
                     items array if necessary.
    ------------------------------------------------------------------------*/

    double calculateTotalAmount() const;
    /*------------------------------------------------------------------------
      Calculate the total cost of all items in the order.

      Precondition:  None.
      Postcondition: Returns the total cost as a double value.
    ------------------------------------------------------------------------*/

    /***** Overloaded Operators *****/
    Order& operator=(const Order& other);
    /*------------------------------------------------------------------------
      Assign the values of one Order to another.

      Precondition:  None.
      Postcondition: The current Order is updated with the values and 
                     dynamically allocated memory of the other Order.
    ------------------------------------------------------------------------*/

    friend ostream& operator<<(ostream& out, const Order& order);
    /*------------------------------------------------------------------------
      Overload the << operator to output an Order's details.

      Precondition:  ostream out is open.
      Postcondition: Outputs the Order's ID, customer name, status, items, 
                     and total amount in a readable format.
    ------------------------------------------------------------------------*/

private:
    int orderId;               // Unique ID for the order
    string customerName;       // Name of the customer who placed the order
    MenuItem* items;           // Dynamic array of items in the order
    int size;                  // Current number of items in the order
    int capacity;              // Maximum capacity of the dynamic array
    char status;               // Status of the order ('P' = Pending, 'C' = Completed)

    void resize();
    /*------------------------------------------------------------------------
      Resize the dynamic array of items when it reaches capacity.

      Precondition:  None.
      Postcondition: The array's capacity is doubled, and existing items
                     are copied to the new array.
    ------------------------------------------------------------------------*/
};

#endif // ORDER_H
