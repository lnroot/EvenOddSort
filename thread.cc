/*
* Lela Root 3/3/2024 Even-Odd Sorting
* C++ file: thread.cc
* Contains the code for each thread to run: compare their assigned index with the next index, swap if necessary using a temp variable
* Update the "swapped" flag if appropriate
*/

#include "thread.h"
#include "ThreadClass.h"
#include "thread-support.cc"

/*
* Function: SortThread
* Contains the code for each thread to run: compare their assigned index with the next index, swap if necessary using a temp variable
* Update the "swapped" flag if appropriate
* Paramaters: int index, bool *swapped, int iteration, int pass, int *array[], int n
*/
void SortThread::ThreadFunc()
{
    Thread::ThreadFunc();

    fprintf(stdout, "        Thread %d-%d created\n", iteration, index); //threads are named with their iteration number and the index they were assigned
    if (index < n-1) { //make sure we weren't given the very last element
        fprintf(stdout, "        Thread %d-%d comparing %d and %d\n", iteration, index, array[index], array[index + 1]);
        if (array[index] > array[index + 1]) { //swap is needed
            fprintf(stdout, "        Thread %d-%d swapping %d and %d\n", iteration, index, array[index], array[index + 1]);
            int temp = array[index];
            array[index] = array[index + 1];
            array[index + 1] = temp;
            *swapped = true;
        }
    }
    fprintf(stdout, "        Thread %d-%d exiting\n", iteration, index);
}

