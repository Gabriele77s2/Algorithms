/* Bubble Sort
It is the simplest sorting algorithm.
It works by repeatedly swapping the adjacent elements if they are in wrong order.

Example:
First Pass:
( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Algorithm compares the first two elements, and swaps since 5 > 1.
( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4
( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Since these elements are already in order (8 > 5), algorithm does not swap them.

Second Pass:
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 )
( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 )
The array is already sorted, but our algorithm does not know if it is completed.
The algorithm needs one whole pass without any swap to know it is sorted.

Third Pass:
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )

Optimized Implementation:
The above function always runs O(n^2) time even if the array is sorted.
It can be optimized by stopping the algorithm if inner loop didn’t cause any swap.

Time Complexity:
Best: Ω(n)
Average: θ(n^2)
Worst: O(n^2)
*/

#include <iostream>
using namespace std;

void swap(int *x, int *y){
   int temp = *x;
   *x = *y;
   *y = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n){
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++){
      swapped = false;
   // Last i elements are already in place
      for (j = 0; j < n-i-1; j++){
         if (arr[j] > arr[j+1]){
            swap(&arr[j], &arr[j+1]);
            swapped = true;
         }
      }
      // Optimized : If inner loop didn't cause any swap
      if (swapped == false){
         break;
      }
    }
}

// Function to print an array
void printArray(int arr[], int size){
   int i;
   for (i = 0; i < size; i++)
      cout << arr[i] << " ";
      cout << endl;
}

// Driver code
int main(){
   int arr[] = {64, 34, 25, 12, 22, 11, 90};
   int n = sizeof(arr)/sizeof(arr[0]);
   bubbleSort(arr, n);
   cout << "Sorted array: \n";
   printArray(arr, n);
   return 0;
}


/* Recursive Bubble Sort
Recursive Bubble Sort has no performance/implementation advantages.
It can be a good question to check understanding of Bubble Sort and recursion.

In first pass, we move largest element to end (Assuming sorting in increasing order).
In second pass, we move second largest element to second last position and so on.

Recursion Idea:
If array size is 1, return.
Do one pass of Bubble Sort. This pass fixes last element of current subarray.
Recur for all elements except last of current subarray.
*/

#include <iostream>
using namespace std;

// A function to implement bubble sort
void bubbleSort(int arr[], int n){
   // If array size is 1, return.
   if (n == 1)
       return;
   // Do one pass of Bubble Sort.
   // After this pass, the largest element is moved to end.
   for (int i=0; i<n-1; i++)
      if (arr[i] > arr[i+1])
         swap(arr[i], arr[i+1]);
    // Largest element is fixed, recur for remaining array
    bubbleSort(arr, n-1);
}

/* Function to print an array */
void printArray(int arr[], int n){
   for (int i=0; i < n; i++)
      cout << arr[i] << " ";
      cout << endl;
}

// Driver program to test above functions
int main(){
   int arr[] = {64, 34, 25, 12, 22, 11, 90};
   int n = sizeof(arr)/sizeof(arr[0]);
   bubbleSort(arr, n);
   cout << "Sorted array: \n";
   printArray(arr, n);
   return 0;
}
