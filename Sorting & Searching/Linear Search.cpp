/* Linear Sort
Problem: Given an array arr[] of n elements, write a function to search a given element x in arr[].

Algorithm:
1. Start from the leftmost element of arr[] and one by one compare x with each element of arr[]
2. If x matches with an element, return the index.
3. If x doesn’t match with any of elements, return -1.

Examples :
Input : arr[] = {10, 20, 80, 30, 60, 50,
                     110, 100, 130, 170}
          x = 110;
Output : 6
Element x is present at index 6

Input : arr[] = {10, 20, 80, 30, 60, 50,
                     110, 100, 130, 170}
           x = 175;
Output : -1
Element x is not present in arr[].
*/

// if x is present then return its location, otherwise return -1
#include <iostream>
using namespace std;

int search(int arr[], int n, int x){
   int i;
   for (i = 0; i < n; i++)
      if (arr[i] == x)
         return i;
   return -1;
}

int main(void){
   int arr[] = { 2, 3, 4, 10, 40 };
   int x = 10;
   int n = sizeof(arr) / sizeof(arr[0]);
   int result = search(arr, n, x);
   (result == -1)? cout<<"Element is not present in array"
                 : cout<<"Element is present at index " <<result;
   return 0;
}
