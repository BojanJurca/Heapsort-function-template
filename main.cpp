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
    
    
    
    
    // vektorji:
    /*
                // https://www.geeksforgeeks.org/sorting-a-vector-in-c/
                vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 }; 
                // cout << v.begin() << " - " << v.end() << endl; --- to ne dela, ker sta begin in end iteratorja
              
                sort(v.begin(), v.end()); 
              
                cout << "Sorted "; 
                for (auto x : v) 
                    cout << x << " "; 
                    
                        
                struct Interval { 
                    int start, end; 
                }; 
                  
                // Compares two intervals according to starting times. 
                /// bool compareInterval(Interval i1, Interval i2) { return (i1.start < i2.start); } 
                
                vector<Interval> vi { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } }; 
              
                // sort the intervals in increasing order of 
                // start time 
                sort(vi.begin(), vi.end(), [] (Interval i1, Interval i2) { return (i1.start < i2.start); }); 
              
                cout << "Intervals sorted by start time : \n"; 
                for (auto x : vi) 
                    cout << "[" << x.start << ", " << x.end << "] "; 


    // locale: https://en.cppreference.com/w/cpp/locale/collate

    std::locale::global(std::locale("en_US.utf8"));
    std::wcout.imbue(std::locale(""));
    std::vector<std::wstring> vl{
        L"ar", L"zebra", L"\u00f6grupp", L"Zebra",
        L"\u00e4ngel",L"\u00e5r", L"f\u00f6rnamn"
    };

    std::wcout << "Default locale collation order: ";
    std::sort(vl.begin(), vl.end());
    for (auto s : vl)
        std::wcout << s << ' ';
    std::wcout << '\n';

    std::wcout << "English locale collation order: ";
    std::sort(vl.begin(), vl.end(), std::locale("en_US.UTF-8"));
    for (auto s : vl)
        std::wcout << s << ' ';
    std::wcout << '\n';

    // std::wcout << "Swedish locale collation order: ";
    // std::sort(vl.begin(), vl.end(), std::locale("sv_SE.UTF-8"));
    // for (auto s : vl)
    //     std::wcout << s << ' ';
    // std::wcout << '\n';

    // https://en.cppreference.com/w/cpp/locale/collate/compare

    */

    return 0;
}




