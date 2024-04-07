/*
* Lela Root 3/3/2024 Even-Odd Sorting
* C++ file: thread-main.cc
* Program that takes as input an array, and sorts the elements using two comparison processes:
* First, a comparison between even elements and their neighboring element, swapping if necessary
* Second, a comparison between odd elements and their neighboring element, swapping if necessary
* Each comparison process will make an individual thread for each individual comparison, and wait for it to terminate before moving on to the next process
* The program terminates when both even and odd processes complete with no swaps, or when the program has iterated n times. 
*/

#include "thread.h"
#include <stdio.h>
#include <stdlib.h>

/*
* Function: main
* Takes standard input, reads it into memory, and iterates through sorting, creating threads for alternating odd and even elements
* Parameters: expects input from a file consisting of one line denoting array size, followed by the array to be sorted
* Calls the SortThread function for each thread it makes
*/
int main(int argc, char** argv) {

     bool swapped;

     //read in array size
     int n;
     scanf("%d\n", &n);

     fprintf(stdout, "Concurrent Even-Odd Sort\n\nNumber of input data = %d\nInput Array:\n", n);

     //array to keep track of threads
     SortThread* Running[n];

     //read in array & output at same time
     int array [n];
     for (int i = 0; i < n; i++){
          scanf("%d ", &array[i]);
          fprintf(stdout, "  %d", array[i]);
     }

     fprintf(stdout, "\n");

     //loop for iterations
     for (int i = 0; i < n; i++) {
          fprintf(stdout, "\n----Iteration %d----\n", i);
          swapped = false;//reset for each iteration
          
          //odd process
          fprintf(stdout, "Odd process\n");
          for (int j = 1; j < n; j = j + 2) { //create n/2 threads
               Running[j] = new SortThread(j, &swapped, i, 0, array, n);
               Running[j]->Begin();
          }

          for (int j = 1; j < n; j = j + 2) {
               Running[j]->Join(); //wait for each odd-process thread to finish
          }

          //even process
          fprintf(stdout, "Even process\n");
          for (int j = 0; j < n; j = j + 2) { //create n/2 threads
               Running[j] = new SortThread(j, &swapped, i, 1, array, n);
               Running[j]->Begin();
          }

          for (int j = 0; j < n; j = j + 2) {
               Running[j]->Join(); //wait for each even-process thread to finish
          }

          fprintf(stdout, "Result after iteration %d:\n", i);
          for (int j = 0; j < n; j++) {
               fprintf(stdout, "  %d", array[j]);
          }
          fprintf(stdout, "\n");

          if (swapped == false) { //check whether array is completely sorted, print output and terminate if it is
               fprintf(stdout, "\nFinal result after iteration %d:\n", i);
               for (int j = 0; j < n; j++) {
                    fprintf(stdout, "  %d", array[j]);
               }
               fprintf(stdout, "\n");

               return 0;

          }

          
     }

     //case where program took all n iterations to sort the array
     fprintf(stdout, "\nFinal result after iteration %d:\n", n-1);
     for (int j = 0; j < n; j++) {
          fprintf(stdout, "  %d", array[j]);
     }
     fprintf(stdout, "\n");

     
}