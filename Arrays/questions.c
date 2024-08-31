#include <stdio.h>
#include <stdlib.h>

void findLargestSmallest(int arr[], int size);
void mergeTwoSorted(int arr1[], int arr2[], int size1, int size2);
int secondLargest(int arr[], int size);

int main(){
    int arr1[] = {34, 72, 13, 44, 25, 30, 10, 78, 66, 19, 100, 99};
    int arr2[] = {0, 72, 13, -1, 2, 3};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    // int size2 = sizeof(arr2) / sizeof(arr2[0]);
    // mergeTwoSorted(arr1, arr2, size1, size2);
    printf("Second Largest : %d",secondLargest(arr1, size1));

    return 0;
}

/*
Write a C program to find the largest and smallest elements in an array.
int arr[] = {34, 72, 13, 44, 25, 30, 10, 78, 66, 19};*/
void findLargestSmallest(int arr[], int size){
    
    for(int i = 0; i<size; i++){
        for(int j = i+1; j<size; j++){
            int temp = arr[i];
            if(arr[i] > arr[j]){
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    printf("Smallest Element : %d\n", arr[0]);
    printf("Largest Element : %d\n", arr[size-1]);

}
/*
Array Rotation:
Write a C program to rotate an array of n elements to the right by k positions.
Reversing an Array:

Implement a function in C to reverse the elements of an array in place.
Array Sorting:

Write a C program to sort an array using the bubble sort algorithm.
Merge Two Sorted Arrays:

*/

void mergeTwoSorted(int arr1[], int arr2[], int size1, int size2){
    int mergedArr[size1+size2];
    for(int i = 0; i<(size1+size2); i++){
        mergedArr[i] = 0;
    }
    for(int i = 0; i<size1; i++){
        mergedArr[i] = arr1[i];
    }
    for(int i = 0; i<size2; i++){
        mergedArr[size1+i] = arr2[i];
    }
    for(int i = 0; i<(size1+size2); i++){
        for(int j = i+1; j<(size1+size2); j++){
            int temp = mergedArr[i];
            if(mergedArr[i] > mergedArr[j]){
                mergedArr[i] = mergedArr[j];
                mergedArr[j] = temp;
            }
        }
    }
    for(int i = 0; i<(size1+size2); i++){
        printf("%d ", mergedArr[i]);
    }
}

/*

Write a C program to merge two sorted arrays into a single sorted array.
Find the Second Largest Element:

*/

// Write a C program to find the second largest element in an array without sorting the array.
int secondLargest(int arr[], int size){
    int track = 0;
    for(int i = 0; i<size; i++){
        if(arr[i] > track){
            track = arr[i];
        }
    }
    int count = 0;
    for(int i = 0; i<size; i++){
        if(arr[i] == track){
            continue;
        }else if(arr[i] > count){
            count = arr[i];
        }
        
    }
    return count;
}


/*
Array Searching:
Implement a C function to search for a specific element in an array using binary search. (Assume the array is sorted)
Finding Duplicates:

Write a C program to find and print all duplicate elements in an array.
Array Rotation Check:

Given two arrays, write a C program to check if one array is a rotation of the other.
Array Majority Element:

Write a C program to find the majority element in an array (an element that appears more than n/2 times).
*/
