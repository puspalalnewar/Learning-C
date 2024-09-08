#include<stdio.h>
int main(){
    
    int sparseMatrix[4][5] = 
    { 
        {0 , 0 , 3 , 0 , 4 }, 
        {0 , 0 , 5 , 7 , 0 }, 
        {0 , 0 , 0 , 0 , 0 }, 
        {0 , 2 , 6 , 0 , 0 } 
    };

    int rowSize = sizeof(sparseMatrix) / sizeof(sparseMatrix[0]);
    int colSize = sizeof(sparseMatrix[0]) / sizeof(sparseMatrix[0][0]);

    int count = 0;
    for(int i = 0; i<rowSize; i++){
        for (int j = 0; j < colSize; j++)
        {
            if(sparseMatrix[i][j] != 0){
                count++;
            }
        }
        
    }
    // printf("%d", count);
    int compactMatrix[3][count];

    int k = 0;
    for(int i = 0; i<rowSize; i++){
        for (int j = 0; j < colSize; j++)
        {
            if(sparseMatrix[i][j] != 0){
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = sparseMatrix[i][j];
                k++;
            }
        }
        
    }
    for(int i = 0; i<3; i++){
        for (int j = 0; j <count; j++)
        {
            printf("%d ", compactMatrix[i][j]);
        }
        printf("\n");
        
    }

    // Output 
    //     Row : 0 0 1 1 3 3 
    //     Col : 2 4 2 3 1 2
    //     Val : 3 4 5 7 2 6

    return 0;
}
