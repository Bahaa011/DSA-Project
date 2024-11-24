/*-- Menu.h -----------------------------------------------------------------

  This header file defines the Menu class, which represents a collection of 
  MenuItem objects. The Menu provides functionalities for adding, deleting, 
  and retrieving items, as well as saving and loading the menu from a file.
  
  Basic operations:
    Constructor:       Initializes the Menu with a default or specified capacity.
    Destructor:        Releases dynamically allocated memory.
    Item management:   Add, delete, retrieve, and reset items in the Menu.
    File operations:   Load items from a file and save items to a file.
    Overloaded <<:     Outputs the entire Menu to an output stream.

  Class Invariant:
    1. The items are stored in a dynamically allocated array.
    2. The size variable represents the number of items currently in the Menu.
    3. The capacity variable determines the maximum number of items the array
       can currently hold. It is increased dynamically as needed.
-----------------------------------------------------------------------------*/

#ifndef MENU_H
#define MENU_H

#include "MenuItem.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class Menu {
private:
    MenuItem* array;  // Dynamic array of MenuItem objects
    int capacity;     // Maximum capacity of the array
    int size;         // Current number of items in the Menu

    void resize();
    /*------------------------------------------------------------------------
      Resize the dynamic array when it reaches capacity.

      Precondition:  None.
      Postcondition: The array's capacity is doubled, and existing items
                     are copied to the new array.
    ------------------------------------------------------------------------*/

public:
    /***** Constructor and Destructor *****/
    Menu(int capacity = 10);
    /*------------------------------------------------------------------------
      Construct a Menu object with a default or specified capacity.

      Precondition:  None.
      Postcondition: The Menu is initialized with a dynamic array of the 
                     specified capacity, size is set to 0.
    ------------------------------------------------------------------------*/

    ~Menu();
    /*------------------------------------------------------------------------
      Destructor: Releases dynamically allocated memory for the array.

      Precondition:  None.
      Postcondition: The memory for the array is deallocated.
    ------------------------------------------------------------------------*/

    /***** Item Retrieval and Management *****/
    MenuItem getItemById(int id);
    /*------------------------------------------------------------------------
      Retrieve a MenuItem by its ID.

      Precondition:  The Menu contains at least one item.
      Postcondition: Returns the MenuItem with the specified ID. Throws an 
                     exception if the item is not found.
    ------------------------------------------------------------------------*/

    void addItem(const MenuItem& item);
    /*------------------------------------------------------------------------
      Add a MenuItem to the Menu.

      Precondition:  None.
      Postcondition: The specified MenuItem is added to the Menu. Resizes the 
                     array if necessary.
    ------------------------------------------------------------------------*/

    bool deleteItem(int id);
    /*------------------------------------------------------------------------
      Delete a MenuItem by its ID.

      Precondition:  The Menu contains at least one item.
      Postcondition: The MenuItem with the specified ID is removed from the 
                     Menu. Returns true if successful, false otherwise.
    ------------------------------------------------------------------------*/

    void reset();
    /*------------------------------------------------------------------------
      Reset the Menu by clearing all items.

      Precondition:  None.
      Postcondition: All items in the Menu are removed, and size is set to 0.
    ------------------------------------------------------------------------*/

    int getLastItemId() const;
    /*------------------------------------------------------------------------
      Retrieve the ID of the last MenuItem added.

      Precondition:  The Menu contains at least one item.
      Postcondition: Returns the ID of the last MenuItem in the array.
    ------------------------------------------------------------------------*/

    /***** File Operations *****/
    void loadFromFile(const string& filename);
    /*------------------------------------------------------------------------
      Load Menu items from a file.

      Precondition:  The file must exist and contain valid MenuItem data.
      Postcondition: The Menu is populated with items from the file. Resizes 
                     the array if necessary.
    ------------------------------------------------------------------------*/

    void saveToFile(const string& filename) const;
    /*------------------------------------------------------------------------
      Save Menu items to a file.

      Precondition:  The output file must be writable.
      Postcondition: All Menu items are saved to the specified file in a
                     readable format.
    ------------------------------------------------------------------------*/

    /***** Overloaded Operators *****/
    friend ostream& operator<<(ostream& out, const Menu& menu);
    /*------------------------------------------------------------------------
      Overload the << operator to output the Menu's details.

      Precondition:  ostream out is open.
      Postcondition: Outputs the Menu's contents, including all items, in
                     a readable format.
    ------------------------------------------------------------------------*/
};

#endif // MENU_H
