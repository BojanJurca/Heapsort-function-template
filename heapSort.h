/*

   heapSort.h
   
   https://github.com/BojanJurca/Heapsort-function-template

   C++ heapSort function template sorts elements in the array.
   The type of elements is not really important. The function template should
   work as expected as long as < operator is provided.
   
   Please note that this is not a description of the heap sort algorithm. If you 
   want to understand how the algorithm works, there are plenty of resources on 
   the internet. For example:
 
        https://www.geeksforgeeks.org/heap-sort/
        https://builtin.com/data-science/heap-sort

   This is just a working function template, in case someone needs it. The emphasis was on 
   the simplicity and ease of use. Trying to put the whole algorithm in a single function 
   required getting rid of the recursive "heapify" function, therefore it was necessary to 
   replicate part of the code.
   
   Basically, all you need to do is to include this file in your project and call the heapSort 
   function. Please, see the examples provided here.

   December 6, 2023, Bojan Jurca
 
*/


template <typename T>
    void heapSort (T arr [], size_t n) { // arguments: the array to be sorted and the number of elements in it
        if (n <= 1) return; // no sorting is needed

        size_t i;
        
        // build heap (rearrange array)
        i = i = n / 2 - 1;
        do {
            
            // heapify i .. n
            int j = i;
            do {
                size_t largest = j;         // initialize largest as root
                size_t left = 2 * j + 1;    // left = 2 * j + 1
                size_t right = 2 * j + 2;   // right = 2 * j + 2
                
                if (left < n && arr [largest] < arr [left]) largest = left;     // if left child is larger than root
                if (right < n && arr [largest] < arr [right]) largest = right;  // if right child is larger than largest so far
                
                if (largest != j) {         // if largest is not root
                    // swap arr [j] and arr [largest]
                    T tmp = arr [j]; arr [j] = arr [largest]; arr [largest] = tmp;
                    // heapify the affected subtree in the next iteration
                    j = largest;
                } else {
                    break;
                }
            } while (true);

        } while (i -- > 0);
        
        // one by one extract an element from heap
        for (i = n - 1; i > 0; i --) {
     
            // move current root to end
            T tmp = arr [0]; arr [0] = arr [i]; arr [i] = tmp;

            // heapify the reduced heap 0 .. i
            size_t j = 0;
            do {
                size_t largest = j;         // initialize largest as root
                size_t left = 2 * j + 1;    // left = 2*j + 1
                size_t right = 2 * j + 2;   // right = 2*j + 2
                
                if (left < i && arr [largest] < arr [left]) largest = left;     // if left child is larger than root
                if (right < i && arr [largest] < arr [right]) largest = right;  // if right child is larger than largest so far
                
                if (largest != j) {         // if largest is not root
                    // swap arr [j] and arr [largest]
                    T tmp = arr [j]; arr [j] = arr [largest]; arr [largest] = tmp;
                    // heapify the affected subtree in the next iteration
                    j = largest;
                } else {
                    break;
                }
            } while (true);            
 
        }

    }
