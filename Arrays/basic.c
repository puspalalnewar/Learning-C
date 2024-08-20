#include <stdio.h>

int main(){
    /*
    Array is a container which can hold a fix number of items and these items should be ofthe  same  type.  Most  of  the  data  structures  make  use  of  arrays  to  implement  their algorithms. 
    Following are the important terms to understand the concept of Array.
    -->Element − Each item stored in an array is called an element.
    -->Index − Each location of an element in an array has a numerical index, which is used to identify the element
    */

    // int arr[] = {1, 2, 3, 4, 5};
    // for(int i = 0; i<5; i++){
    //     printf("%d\n", arr[i]);
    // }
    // printf("%d",arr[4]);

    // Search the given number (12) in arr if not get return -1;
    // int arr[5];
    // int length = sizeof(arr) / sizeof(arr[0]);
    // for(int i = 0; i<5; i++) {
    //     printf("Enter no : ");
    //     scanf("%d", &arr[i]);
    // }
    // for(int i = 0; i<5; i++){
    //     if (arr[i] == 12)
    //     {
    //         printf("Index : %d", i);
    //     }
    // }

    // int[] arr = {1, 2, 3, 4, 5};
    // int arr[5];
    // int size = sizeof(arr) / sizeof(arr[0]);
    // // printf("%d", size);
    // for(int i = 0; i<size; i++){
    //     printf("Enter Element");
    //     scanf("%d", &arr[i]);
    // }
    int arr[] = {10, 20, 15, 2, 23, 90, 67};
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i<size; i++){
       if(arr[i] < arr[i+1] ){
        printf("First Neighbour Greater Element : %d\n",arr[i+1]);
        break;
       }
    }
    for(int i = 0; i<size; i++){
       for(int j = i+1; j<size; j++){
        int temp;
        if(arr[i] < arr[j]){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
       }
    }
    // for(int i = 0; i<size; i++){
    //     printf("%d ", arr[i]);
    // }
    printf("The Largest Element : %d", arr[0]);


    return 0;
}