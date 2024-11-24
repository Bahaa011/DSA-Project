/*-- Menu.cpp --------------------------------------------------------------
              This file implements Menu member functions.
--------------------------------------------------------------------------*/

#include "Menu.h"

//--- Definition of Menu constructor
Menu::Menu(int capacity){
    size = 0;
    this->capacity = capacity;
    array = new MenuItem[capacity];
}

//--- Definition of Menu destructor
Menu::~Menu(){
    delete [] array; // Free the memory
}

//--- Definition of resize()
void Menu::resize(){
    // Allocate new memory and copy items
    MenuItem* newArray = new MenuItem[capacity*2];
    for(int i = 0; i < size; i++){
        newArray[i] = array[i]; // Copy each item
    }
    
    capacity *= 2;
    delete [] array;
    array = newArray;
}

//--- Definition of getItemById()
MenuItem Menu::getItemById(int id) {
    for(int i = 0; i < size; i++){
        if(id == array[i].getId()){
            return array[i];
        }
    }

    return MenuItem(-1, "", "", 0.99);
}

//--- Definition of addItem()
void Menu::addItem(const MenuItem& item){
    if(size == capacity) // if array is full we double the capacity
        resize();
    
    array[size] = item;
    size++;
}

//--- Definition of deleteItem()
bool Menu::deleteItem(int id){
    int index = -1;
    
    for(int i = 0; i < size; i++){
        if(id == array[i].getId()){
            index = i;
            break;
        }
    }
    
    if(index == -1)
        return false;
    
    for(int i = index; i < size - 1; i++){
        array[i] = array[ i + 1 ];
    }
    
    size--;
    return true;
}

//--- Definition of reset()
void Menu::reset(){
    delete [] array; // Free the memory
    size = 0;
    array = new MenuItem[capacity];
}

//--- Definition of getLastItemId()
int Menu::getLastItemId() const {
    return array[size-1].getId();
}

//--- Definition of loadFromFile()
void Menu::loadFromFile(const string& filename) {
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, name, description, priceStr;

        // Split the line by commas
        getline(ss, idStr, ',');   // Read id
        getline(ss, name, ',');    // Read name
        getline(ss, description, ','); // Read description
        getline(ss, priceStr);    // Read price

        // Convert id and price from strings to appropriate types
        int id = stoi(idStr); // Convert ID from string to integer
        double price = stod(priceStr); // Convert price from string to double

        // Create a new MenuItem and add it to the menu
        MenuItem item(id, name, description,price);
        addItem(item);
    }

    file.close(); // Close the file
}

//--- Definition of saveToFile()
void Menu::saveToFile(const string& filename) const {
    ofstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    for(int i = 0; i < size; i++){
        file << array[i].getId() << "," << array[i].getName() << ","
                << array[i].getDescription() << "," 
                << array[i].getPrice() << endl; // Write to the file
    }
    
    file.close(); // Close the file
}

//--- Definition of overloaded operator<<()
ostream& operator<<(ostream& out, const Menu& menu){
    out << "--- Menu Items ---" << endl;

    if(menu.size == 0){
        out << "No items on menu." << endl;
    }

    for(int i = 0; i < menu.size; i++){
        out << menu.array[i];
    }

    return out;
}
