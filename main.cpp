/*

   main.cpp
   
   https://github.com/BojanJurca/Heapsort-function-template

   Examples of the use of heapSort function template.

   December 6, 2023, Bojan Jurca
 
*/


#include <iostream>

using namespace std;

#include "heapSort.h"


int main () {

    // heapSort-ing arrays of different types, as long as < operator is provided ...
    
    int intArray [] = {3, 6, 4, 1, 8, 6, 3, -1, 0, -3};
    
    heapSort (intArray, sizeof (intArray) / sizeof (intArray [0]));

    cout << "\n\n sorted intArray: ";
    for (int i = 0; i < sizeof (intArray) / sizeof (intArray [0]); i++)
        cout << intArray [i] << "   ";
    

    string stringArray [] = {"Pascal", "C", "Ada", "C++", "Fortran", "C#"};

    heapSort (stringArray, sizeof (stringArray) / sizeof (stringArray [0]));

    cout << "\n\n sorted stringArray: ";
    for (int i = 0; i < sizeof (stringArray) / sizeof (stringArray [0]); i++)
        cout << stringArray [i] << "   ";


    // ... or use your own < operator

    class barString : public string {
        public:
            // let one string be < than the other if it holds a shorter bar
            bool operator < (const barString& other) { return this->length () < other.length (); }
    };
    
    barString bars [] = {"▄▄▄", "▄▄▄▄▄", "▄▄▄▄▄", "▄", "▄▄▄▄▄▄▄▄","▄▄▄▄▄▄", "▄▄▄", "▄"};
    
    heapSort (bars, sizeof (bars) / sizeof (bars [0]));

    std::cout << "\n\n sorted bars\n";
    for (int i = 0; i < sizeof (bars) / sizeof (bars [0]); i++)
        std::cout << "   " << bars [i] << endl;    

   
    return 0;
}




