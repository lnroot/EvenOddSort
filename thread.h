/*
* Lela Root 3/3/2024 Even-Odd Sorting
* header file: thread.h
* Contains the class & function declaration for the SortThread class & function 
*/

#include "ThreadClass.h"

class SortThread : public Thread
{
     public:
          SortThread(int index, bool* swapped, int iteration, int pass, int array[], int n):index(index), swapped(swapped), iteration(iteration), pass(pass), array(array), n(n)
          {};

     private:
          void ThreadFunc();
          int index; //index of element assigned to the current thread
          bool *swapped; //whether a swap happened during this iteration
          int iteration; //the current iteration
          int pass; //whether current pass is even or odd
          int *array; //array to be sorted
          int n; //size of the array to be sorted
        
};