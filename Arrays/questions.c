#include <stdio.h>
#include <stdlib.h>

void findLargestSmallest(int arr[], int size);
void mergeTwoSorted(int arr1[], int arr2[], int size1, int size2);
int secondLargest(int arr[], int size);
int binarySearch(int arr[], int size, int target);
void reverseArr(int arr[], int size);

int main(){
    int arr[] = {34, 72, 13, 44, 25, 30, 10, 78, 66, 19, 100, 99};
    int size = sizeof(arr) / sizeof(arr[0]);
   
    

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
*/

// Implement a function in C to reverse the elements of an array.
void reverseArr(int arr[], int size){
    int newArr[size];
    for(int i = size-1, j = 0; i>=0 && j<size; i--, j++){
        newArr[j] = arr[i];
    }
    for(int i = 0; i<size; i++){
        arr[i] = newArr[i];
    }
}

/*
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



// Implement a C function to search for a specific element in an array using binary search. (Assume the array is sorted)

int binarySearch(int arr[], int size, int target){
    int mid = size / 2;
    int left = 0;
    int right = size-1;

    while (left <= right){
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] < target){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    
    return -1;
}

/*
Array Se
Finding Duplicates:
Write a C program to find and print all duplicate elements in an array.
Array Rotation Check:

Given two arrays, write a C program to check if one array is a rotation of the other.
Array Majority Element:

Write a C program to find the majority element in an array (an element that appears more than n/2 times).
*/
