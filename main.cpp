/*---------------------------------------------------------------------
  Restaurant Order Management System

  This program simulates the management of a restaurant's menu and orders.
  It allows the user to perform various operations such as managing the menu,
  placing orders, processing them, and calculating total revenue from orders.

  Input:  User choices for various menu operations and inputs such as item
          details, customer names, and order IDs.
  Output: Displays the menu, order status, revenue reports, and various
          success/error messages.

  Methods:
    - `addMenuItem`: Adds a new menu item based on user input.
    - `deleteMenuItem`: Deletes a menu item by its ID.
    - `resetMenu`: Resets the menu to an empty state.
    - `addNewOrder`: Allows the user to create a new order by selecting menu items.
    - `processNextOrder`: Processes the next order in the queue.
    - `displayOrder`: Displays pending and completed orders.
    - `deleteOrder`: Deletes an order from the queue by its ID.
    - `calculateTotalRevenue`: Calculates and displays the total revenue from all completed orders.
    - `saveCompletedOrdersToFile`: Saves all completed orders to a file.
    - `exit`: Saves the current menu to a file and exits the program.

  Note:
    - The program assumes that the `Menu`, `OrderQueue`, `CompletedOrderStack`,
      and `Order` classes have been implemented with the required functionality.
  ---------------------------------------------------------------------*/

// Include necessary headers
#include "Menu.h"
#include "MenuItem.h"
#include "CompletedOrderStack.h"
#include "OrderQueue.h"
#include "Order.h"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <ctime>
#include <sstream>

using namespace std;

// Function declarations
void display();
int getChoice();
void addMenuItem(int &itemId, Menu &menu);
void deleteMenuItem(Menu &menu);
void resetMenu(Menu &menu);
void addNewOrder(int &orderId ,OrderQueue &order, Menu &menu);
void processNextOrder(OrderQueue &order, CompletedOrderStack &completedOrder);
void displayOrder(OrderQueue &order, CompletedOrderStack &completedOrder);
void deleteOrder(OrderQueue &order);
void calculateTotalRevenue(CompletedOrderStack &completedOrder);
void saveCompletedOrdersToFile(CompletedOrderStack &completedOrder);
void exit(Menu &menu);

int main() {
    
    Menu menu;                          // Manages the restaurant's menu
    OrderQueue order;                   // Handles pending orders
    CompletedOrderStack completedOrder; // Stores completed orders
    int orderId = 1;                    // Unique identifier for orders

    menu.loadFromFile("menu.txt");          // Load menu data from file
    int itemId = menu.getLastItemId() + 1;  // Initialize item ID counter for new items
    
    int choice;  // User menu choice
    do{
        display();            // Display menu options
        choice = getChoice(); // Get user's choice
        
        cout << endl;
        
        switch (choice) {
            case 1: cout << menu; break;
            case 2: addMenuItem(itemId, menu); break;
            case 3: deleteMenuItem(menu); break;
            case 4: resetMenu(menu); break;
            case 5: addNewOrder(orderId, order, menu); break;
            case 6: processNextOrder(order, completedOrder); break;
            case 7: displayOrder(order, completedOrder); break;
            case 8: deleteOrder(order); break;
            case 9: calculateTotalRevenue(completedOrder); break;
            case 10: saveCompletedOrdersToFile(completedOrder); break;
            case 11: exit(menu); break;
        }
        
        cout << endl;
    } while(choice != 11); // Loop until the user exits

    return 0;
}

/**
 * display()
 * Purpose:
 *   Displays the main menu options for the system.
 * Functionality:
 *   - Prints menu options (1–11) for the restaurant order management system.
 * Input: None
 * Output: Menu options displayed on the console.
 * Usage: Allows the user to choose system operations.
 */
int getChoice() {
    int choice;
    while (true) {
        cout << "Enter your choice (1-11): ";
        cin >> choice;

        // Check if input is valid and in the range
        if (cin.fail() || choice < 1 || choice > 11) {
            cout << "Invalid input. Please enter a number between 1 and 11." 
                << endl;

            // Clear error flags and discard invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break; // Valid input, exit the loop
        }
    }

    return choice;
}

/**
 * display()
 * Purpose:
 *   Displays the main menu options for the restaurant order management system.
 * Functionality:
 *   - Prints numbered menu options (1–11) 
 *          that correspond to the program's main operations.
 * Input: None
 * Output: Displays menu options on the console.
 * Usage: Helps the user navigate through the system functionalities.
 */
void display(){
    cout << "--- Restaurant Order Management System ---" << endl;
    cout << "1. Display Menu" << endl;
    cout << "2. Add Menu Item" << endl;
    cout << "3. Delete Menu Item" << endl;
    cout << "4. Reset Menu" << endl;
    cout << "5. Add New Order" << endl;
    cout << "6. Process Next Order" << endl;
    cout << "7. Display Orders" << endl;
    cout << "8. Delete Order" << endl;
    cout << "9. Calculate Total Amount of Sold Orders" << endl;
    cout << "10. Save Completed Orders to File" << endl;
    cout << "11. Exit" << endl;
}

/**
 * addMenuItem(int &itemId, Menu &menu)
 * Purpose:
 *   Allows the user to add a new item to the restaurant menu.
 * Functionality:
 *   - Prompts the user to input:
 *     - Item name (validated to be non-empty).
 *     - Item description (validated to be non-empty).
 *     - Item price (validated to be greater than 0).
 *   - Creates a new `MenuItem` object and adds it to the `menu`.
 * Input:
 *   - `itemId` (Reference): The current item ID to be assigned.
 *   - `menu` (Menu object): The menu to which the item will be added.
 * Output: Confirmation of success or failure.
 * Usage: Adds a new menu item with details provided by the user.
 */
void addMenuItem(int &itemId, Menu &menu){
    string name;
    string description;
    double price;

    // Prompt for item's name
    cout << "Enter item name: ";
    cin.ignore(); 
    getline(cin, name);
    while (name.empty()) {
        cout << "Item name cannot be empty. Please enter a valid name: ";
        getline(cin, name);
    }
    
    // Prompt for item's description
    cout << "Enter description: ";
    cin.ignore();
    getline(cin, description);
    while (description.empty()) {
        cout << "Item description cannot be empty." 
                << "Please enter a valid description: ";
        getline(cin, description);
    }

    // Prompt for item's price
    cout << "Enter item price: ";
    while (true) {
        cin >> price;
        if (price > 0) break;
        cout << "Please enter a valid price greater than 0: ";
        cin.clear();  // Clear any error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
    }
                
    MenuItem item(itemId++, name, description, price);
    menu.addItem(item);

    cout << "Item added successfully to the menu." << endl;    
}

/**
 * deleteMenuItem(Menu &menu)
 * Purpose:
 *   Deletes an item from the menu by its ID.
 * Functionality:
 *   - Prompts the user for an item ID.
 *   - Validates the input (must be a positive integer).
 *   - Deletes the item if found; otherwise, displays an error message.
 * Input: 
 *   - `menu` (Menu object): The menu from which the item will be deleted.
 * Output: Confirmation of success or failure.
 * Usage: Removes a specific item from the menu.
 */
void deleteMenuItem(Menu &menu){
    int id;

    // Prompt for item's ID to be deleted
    cout << "Enter item ID to delete: ";
    while (true) {
        cin >> id;
        if (id > 0)
            break;
                    
        cout << "Please enter a positive integer for the item ID: ";
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
    }

    if(menu.deleteItem(id)){
        cout << "Item Deleted Successfully." << endl;
    } else {
        cout << "Item not found." << endl;
    }
}

/**
 * resetMenu(Menu &menu)
 * Purpose:
 *   Clears all items from the menu.
 * Functionality:
 *   - Invokes the `reset()` function on the `menu` object to delete all items.
 * Input:
 *   - `menu` (Menu object): The menu to be cleared.
 * Output: Confirmation message.
 * Usage: Resets the menu to an empty state.
 */
void resetMenu(Menu &menu){
    menu.reset(); // Call the reset menu function

    cout << "Menu successfully reset." << endl;
}

/**
 * addNewOrder(int &orderId, OrderQueue &order, Menu &menu)
 * Purpose:
 *   Adds a new order to the order queue.
 * Functionality:
 *   - Prompts the user for the customer name and item IDs.
 *   - Validates item IDs by checking if they exist in the menu.
 *   - Adds valid items to the order and assigns a unique order ID.
 * Input:
 *   - `orderId` (Reference): The current order ID to be assigned.
 *   - `order` (OrderQueue object): The queue to which the order will be added.
 *   - `menu` (Menu object): Used to validate item IDs.
 * Output: Confirmation of success or failure.
 * Usage: Creates a new order with items and adds it to the queue.
 */
void addNewOrder(int &orderId, OrderQueue &order, Menu &menu){
    string name;
    int id;

    // Prompt for the customers name
    cout << "Enter customer name: ";
    cin.ignore();  // Clear the newline character
    getline(cin, name);
    while (name.empty()) {
        cout << "Customer name cannot be empty. Please enter a valid name: ";
        getline(cin, name);
    }

    // Prompt for items to be ordered by their ID
    cout << "Enter item IDs (0 to finish): ";

    Order o(orderId, name);
    while(true){
        cin >> id;
        if (cin.fail()) {
            // Clear error flags and ignore invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid item ID: ";
            continue;
        }

        if(id == 0){
            break;
        }

        MenuItem item = menu.getItemById(id);
        if (item.getId() != -1) { // Invalid items return an ID of -1
            o.addItem(item);
        } else {
            cout << "Item with ID " << id << " not found." << endl;
        }
    }

    if (o.isEmpty()) {
        cout << "No valid items were added. Order not created." << endl;
    } else {
        order.enqueue(o);
        cout << "Order added successfully!" << endl;
        orderId++;
    }
}

/**
 * processNextOrder(OrderQueue &order, CompletedOrderStack &completedOrder)
 * Purpose:
 *   Processes the next order in the queue and moves it to the completed orders stack.
 * Functionality:
 *   - Removes the first order from the queue.
 *   - Pushes the processed order to the completed orders stack.
 * Input:
 *   - `order` (OrderQueue object): The queue from which the next order is processed.
 *   - `completedOrder` (CompletedOrderStack object): The stack to store completed orders.
 * Output: Confirmation of success or error if no orders are available.
 * Usage: Handles the transition of orders from pending to completed.
 */
void processNextOrder(OrderQueue &order, CompletedOrderStack &completedOrder){
    if (order.isEmpty()) {
        cout << "No orders to process!" << endl;
    } else {
        // Process the next order
        Order nextOrder = order.dequeue();
        cout << "Processing order for "<< nextOrder.getCustomerName() << "..." << endl;

        // Move it to Completed Orders stack
        completedOrder.push(nextOrder);
        cout << "Order processed succesfully!" << endl;
    }
}

/**
 * displayOrder(OrderQueue &order, CompletedOrderStack &completedOrder)
 * Purpose:
 *   Displays all current orders and completed orders.
 * Functionality:
 *   - Prints the details of all orders in the `order` queue.
 *   - Prints the details of all orders in the `completedOrder` stack.
 * Input:
 *   - `order` (OrderQueue object): Pending orders to display.
 *   - `completedOrder` (CompletedOrderStack object): Completed orders to display.
 * Output: Lists of pending and completed orders.
 * Usage: Provides a summary of all orders in the system.
 */
void displayOrder(OrderQueue &order, CompletedOrderStack &completedOrder){
    cout << order; // Display all active orders
    cout << completedOrder; // Display all completed orders
}

/**
 * deleteOrder(OrderQueue &order)
 * Purpose:
 *   Deletes a specific order from the order queue.
 * Functionality:
 *   - Prompts the user for the order ID.
 *   - Validates the input (must be a positive integer).
 *   - Deletes the order if found; otherwise, displays an error message.
 * Input:
 *   - `order` (OrderQueue object): The queue from which the order will be deleted.
 * Output: Confirmation of success or failure.
 * Usage: Removes a specific order from the queue.
 */
void deleteOrder(OrderQueue &order){
    int id;

    // Prompt for order ID to be deleted
    cout << "Enter order id to delete: ";
    while (true) {
        cin >> id;
        if (id > 0)
            break;
        
        cout << "Please enter a positive integer for the order ID: ";
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
    }

    if(order.deleteOrder(id)){
        cout << "Order deleted succesfully." << endl;
    } else {
        cout << "Order not found." << endl;
    }
}

/**
 * calculateTotalRevenue(CompletedOrderStack &completedOrder)
 * Purpose:
 *   Calculates and displays the total revenue from completed orders.
 * Functionality:
 *   - Iterates through the completed orders stack to calculate individual order totals.
 *   - Displays the total revenue of all completed orders.
 * Input:
 *   - `completedOrder` (CompletedOrderStack object): The stack of completed orders.
 * Output: Total revenue from all completed orders.
 * Usage: Provides a financial summary of completed orders.
 */
void calculateTotalRevenue(CompletedOrderStack &completedOrder){
    cout << "--- Total Revenue ---" << endl;

    int size = completedOrder.size();
    for (int i = 0; i < size; i++) {
        Order o = completedOrder.getOrder(size - i - 1);  // Get each completed order
        double orderTotal = o.calculateTotalAmount();  // Calculate the total for the order
        cout << "Order " << i + 1 << ": $" << orderTotal << endl;
    }

    cout << "Total Sold: $" << completedOrder.calculateTotalRevenue() << endl;
}

/**
 * saveCompletedOrdersToFile(CompletedOrderStack &completedOrder)
 * Purpose:
 *   Saves all completed orders to a file.
 * Functionality:
 *   - Writes the details of completed orders to a specified file (`completed_orders.txt`).
 * Input:
 *   - `completedOrder` (CompletedOrderStack object): The stack of completed orders.
 * Output: Confirmation of success.
 * Usage: Ensures order data is persisted for future reference.
 */
void saveCompletedOrdersToFile(CompletedOrderStack &completedOrder){
    cout << "Saving completed orders to file..." << endl;

    // Get the current date
    time_t now = time(0);
    tm *time = localtime(&now);

    // Create the file name with the date
    stringstream filename;
    filename << "completed_orders (" 
             << (1900 + time->tm_year) << "-" 
             << (time->tm_mon + 1) << "-" 
             << time->tm_mday << ").txt";

    completedOrder.saveToFile(filename.str());

    cout << "Orders saved successfully!" << endl;
}

/**
 * exit(Menu &menu)
 * Purpose:
 *   Safely exits the program and saves the current menu to a file.
 * Functionality:
 *   - Writes the menu data to a specified file (`menu.txt`).
 *   - Displays a goodbye message and terminates the program.
 * Input:
 *   - `menu` (Menu object): The menu to be saved.
 * Output: Goodbye message.
 * Usage: Ensures the menu is saved before exiting the program.
 */
void exit(Menu &menu){
    cout << "Exiting the program... Goodbye!";
    menu.saveToFile("menu.txt");
}
