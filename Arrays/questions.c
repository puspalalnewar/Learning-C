#include <stdio.h>
#include <stdlib.h>

void findLargestSmallest(int arr[], int size);

int main(){
    int arr[] = {34, 72, 13, 44, 25, 30, 10, 78, 66, 19};
    int size = sizeof(arr) / sizeof(arr[0]);

    findLargestSmallest(arr, size);
    for(int i = 0; i<10; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

// Write a C program to find the largest and smallest elements in an array.
// int arr[] = {34, 72, 13, 44, 25, 30, 10, 78, 66, 19};
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