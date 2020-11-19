/* Divide and Conquer
This technique can be divided into three parts:
1. Divide: This involves dividing the problem into some sub problem.
2. Conquer: Sub problem by calling recursively until sub problem solved.
3. Combine: The Sub problem Solved so that we will get find problem solution.

Algorithm:
DAC(a, i, j){
    if(small(a, i, j))
      return(Solution(a, i, j))
    else
      m = divide(a, i, j)               // f1(n)
      b = DAC(a, i, mid)                 // T(n/2)
      c = DAC(a, mid+1, j)            // T(n/2)
      d = combine(b, c)                 // f2(n)
   return(d)
}

Example:
To find the maximum and minimum element in a given array.
Input: { 70, 250, 50, 80, 140, 12, 14 }
Output: The minimum number in a given array is : 12
        The maximum number in a given array is : 250

Approach:
To find the maximum and minimum element from a given array is an application for Divide and Conquer.

For Maximum:
We are using the recursive approach where only two elements are left and then we can using condition, if(a[index]>a[index+1]).
a[index] and a[index+1] condition will ensure only two elements in left.

if(index >= l-2)
{
if(a[index]>a[index+1])
{
// a[index]
// the last element will be maximum in a given array.
}
else
{
// a[index+1]
// the last element will be maximum in a given array.
}
}

Now we have to see the right side condition to find the maximum.
Recursive function to check the right side at the current index of an array.

// Recursive call
max = DAC_Max(a, index+1, l);

We will compare the condition and check the right side at the current index of a given array.

// Right element will be maximum.
if(a[index]>max)
return a[index];
// max will be maximum element in a given array.
else
return max;
}

For Minimum:
We are going to implement the recursive approach to find the minimum in a given array.

int DAC_Min(int a[], int index, int l)
//Recursive call function to find the minimum in a given array.

if(index >= l-2)
// to check the condition that there will be two-element in the left
   then we can find the minimum element in a given array.
{
// we will check the condition
if(a[index]<a[index+1])
return a[index];
else
return a[index+1];
}

We will check the condition on the right side in a given array.

// Recursive call for the right side in the given array.
min = DAC_Min(a, index+1, l);

We will check the condition to find the minimum on the right side.

// Right element will be minimum
if(a[index]<min)
return a[index];
// min will be minimum in a given array.
else
return min;
*/

#include <stdio.h>
int DAC_Max(int a[], int index, int l);
int DAC_Min(int a[], int index, int l);

// function to find the maximum in a given array.
int DAC_Max(int a[], int index, int l){
   int max;
   if (index >= l - 2){
      if (a[index] > a[index + 1])
         return a[index];
      else
         return a[index + 1];
    }

    // logic to find the max in the given array.
    max = DAC_Max(a, index + 1, l);
    if (a[index] > max)
        return a[index];
    else
        return max;
}

// Function to find the minimum in a given array.
int DAC_Min(int a[], int index, int l){
   int min;
   if (index >= l - 2) {
      if (a[index] < a[index + 1])
         return a[index];
      else
         return a[index + 1];
    }

    // Logic to find the min in the given array.
    min = DAC_Min(a, index + 1, l); 
    if (a[index] < min)
        return a[index];
    else
        return min;
}

// Driver Code
int main(){
   // Defining the variables
   int min, max, N;
   // Initializing the array
   int a[7] = { 70, 250, 50, 80, 140, 12, 14 };
   // recursion - DAC_Max function called
   max = DAC_Max(a, 0, 7);
   // recursion - DAC_Max function called
   min = DAC_Min(a, 0, 7);
   printf("The minimum number in a given array is : %d\n", min);
   printf("The maximum number in a given array is : %d", max);
   return 0;
}
