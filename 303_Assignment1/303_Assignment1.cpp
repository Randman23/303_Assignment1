#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;
const int MAX_SIZE = 1000; // Maximum size of the array

// Function that finds the index of the integer the user asks
int findIndex(const int array[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == target) {   
            return i; 
        }
    }
    return -1; 
}


int modifyvalue(int array[], int index, int newvalue, int oldvalue, int returnednewvalue)
//to change the value in the array 
{
    try {
        if (array[index] < 0 || index >= MAX_SIZE) {
            throw std::out_of_range("Index out of bounds.");
        }

        oldvalue = array[index]; // Set the old value to the index
        array[index] = newvalue; // Set the index to the new value
        returnednewvalue = newvalue; // Show the new value returned by the function
    }
    catch (const std::out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

 void addIntToArray(int array[], int& size, int newnumber, int index) 
     //function to add an int to the end of the array 
{
    if (size < MAX_SIZE) //checking to make sure that it is in range 
    {
        array[size] = newnumber; //add the integer to the end of the array 
        size++; // increase the size of the array where the index is held 
        
    }
    else {
        cerr << "Array is full cannot add anymore integers."; //show that the array is out of size 

    }

   
    
}


 void replaceint(int array[], int& size, int indextomodify, bool remove) {
     try {
         if (indextomodify < 0 || indextomodify >= size) {
             throw std::out_of_range("Index is out of bounds.");
         }

         if (remove) {
             for (int i = indextomodify; i < size - 1; i++) {
                 array[i] = array[i + 1];
             }
             --size;
         }
         else {
             array[indextomodify] = 0;
         }
     }
     catch (const std::out_of_range& e) {
         cerr << "Error: " << e.what() << endl;
     }
 }





int main() {
    int array[MAX_SIZE]; // Array to hold the data from the file
    int size = 0; // Current size of the array
    string filename = "input.txt"; // Name of the input file
    int oldvalue = 0;
    int newvalue = 0;
    int returnednewvalue = 0;
    int newnumber = 0;
    int indextomodify = 0; 
    bool remove = true; 
    


    // Open the input file
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file: " << filename << endl;
        return 1; // Return with an error code
    }

    // Read data from the file into the array
    while (infile >> array[size]) {
        ++size; // increase the size of the array to match the file being read 
        if (size >= MAX_SIZE) { // check to ensure that the array has not crossed the max size 
            cout << "Array size exceeded maximum limit of " << MAX_SIZE << endl;
            break; // Stop reading if the array is full
        }
    }
    infile.close(); // Close the file

    // Prompt user for the number to find
    int numberToFind; //create a variable for the user to ask 
    cout << "Enter the number to find: ";
    cin >> numberToFind;

    // Find the index of the number in the array
    int index = findIndex(array, size, numberToFind);

    if (index != -1) {
        cout << "Number " << numberToFind << " found at index " << index << "." << endl;
        //Give the index and numbers location in the array 
    }
    else {
        cout << "Number " << numberToFind << " not found in the array." << endl;
        // Give the number and show that it is not found in the array
    }

    cout << "Enter desired index to change. "; // find the index that user wants to change 
    cin >> index; 
    oldvalue = array[index]; //set the old value to the index
    cout << "The value is. " << array[index];
    cout << "  Enter the index's new value. "; //find the new value that the user wants 
    cin >> newvalue;
    
    modifyvalue( array,  index,  newvalue,  oldvalue,  returnednewvalue); //modify the array and set returned value 

    std::cout << "Old value: " << oldvalue << endl;
    std::cout << "New value: " << newvalue << endl; //print the new infromation 
    
    cout << "Add a new integer. "; //ask to add a new integer 
    cin >> newnumber; //have the user add the new number 
   
    addIntToArray(array, size, newnumber, index); //call the function that was used before 

    cout << "New Array: "; // print the whole array with the new integer 
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";

    }
    cout << endl;
    

    cout << "Type the index of number that you want to remove. ";
    cin >> indextomodify;

    try {
        replaceint(array, size, indextomodify, remove);
    }
    catch (const std::out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    cout << "New Array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}