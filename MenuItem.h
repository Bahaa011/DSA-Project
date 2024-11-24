/*-- MenuItem.h --------------------------------------------------------------
 
  This header file defines the MenuItem class, which represents an individual 
  item on a menu. Each MenuItem has a unique ID, name, description, and price.
  
  Basic operations:
    Constructor:     Constructs a MenuItem with default or specified values.
    Accessors:       Get individual attributes (ID, name, description, price).
    Mutators:        Set individual attributes (ID, name, description, price).
    Overloaded <<:   Outputs the MenuItem details to an output stream.
 
  Class Invariant:
    1. ID is a unique positive integer.
    2. Name and description are non-empty strings.
    3. Price is a non-negative double value.
-----------------------------------------------------------------------------*/
#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>

using namespace std;

class MenuItem {
private:
    int id;                 // Unique ID for the menu item
    string name;            // Name of the menu item
    string description;     // Description of the menu item
    double price;           // Price of the menu item

public:
    /***** Constructor *****/
    MenuItem(int id = 0, const string& name = "undefined",
     const string& description = "undefined",double price = 0.0);
    /*------------------------------------------------------------------------
      Construct a MenuItem object with default or specified values.

      Precondition:  None.
      Postcondition: MenuItem is initialized with given ID, name, description,
                     and price, or default values if not provided.
    ------------------------------------------------------------------------*/

    /***** Accessor Functions *****/
    int getId() const;
    /*------------------------------------------------------------------------
      Retrieve the ID of the MenuItem.

      Precondition:  None.
      Postcondition: Returns the ID of the menu item.
    ------------------------------------------------------------------------*/

    string getName() const;
    /*------------------------------------------------------------------------
      Retrieve the name of the MenuItem.

      Precondition:  None.
      Postcondition: Returns the name of the menu item.
    ------------------------------------------------------------------------*/

    string getDescription() const;
    /*------------------------------------------------------------------------
      Retrieve the description of the MenuItem.

      Precondition:  None.
      Postcondition: Returns the description of the menu item.
    ------------------------------------------------------------------------*/

    double getPrice() const;
    /*------------------------------------------------------------------------
      Retrieve the price of the MenuItem.

      Precondition:  None.
      Postcondition: Returns the price of the menu item.
    ------------------------------------------------------------------------*/

    /***** Mutator Functions *****/
    void setId(int id);
    /*------------------------------------------------------------------------
      Set the ID of the MenuItem.

      Precondition:  ID must be a unique positive integer.
      Postcondition: Updates the menu item's ID to the specified value.
    ------------------------------------------------------------------------*/

    void setName(const string& name);
    /*------------------------------------------------------------------------
      Set the name of the MenuItem.

      Precondition:  Name must be a string.
      Postcondition: Updates the menu item's name to the specified value.
    ------------------------------------------------------------------------*/
    
    void setDescription(const string& description);
    /*------------------------------------------------------------------------
      Set the description of the MenuItem.

      Precondition:  Description must be a string.
      Postcondition: Updates the menu item's description to the specified value.
    ------------------------------------------------------------------------*/
    
    void setPrice(double price);
    /*------------------------------------------------------------------------
      Set the price of the MenuItem.

      Precondition:  Price must be a non-negative value.
      Postcondition: Updates the menu item's price to the specified value.
    ------------------------------------------------------------------------*/

    /***** Overloaded Operators *****/
    friend ostream& operator<<(ostream& out, const MenuItem& menuItem);
    /*------------------------------------------------------------------------
      Overload the << operator to output a MenuItem's details.

      Precondition:  ostream out is open.
      Postcondition: Outputs the MenuItem's ID, name, description, and price
                     in a readable format.
    ------------------------------------------------------------------------*/
};

#endif // MENUITEM_H
