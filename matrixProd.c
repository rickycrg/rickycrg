#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//program that manage 2d structures via linearized memory avoiding the use of the pointer-to-pointer (int**)
//using a normal pointer with the size of (row * col)
//using dynamic memory allocation (malloc/calloc) in the safest way
//scope of the program is a simple matrix multiplication


void printMatrix(int r, int c, int *matrix){ //function to print matrix (simple but useful)

    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            printf("%d ", matrix[(i*c)+j]);
        }
        printf("\n");
    }
}

int main (void){

//using for example row = 3 and col = 3, but the implementation supports user inputs
    int r1 = 3;
    int c1 = 3;

    srand(time(NULL));

    int *matrix=malloc((r1*c1)*(sizeof(int)));

    for (int i=0;i<r1;i++){
        for (int j=0;j<c1;j++){
            matrix[(i*c1)+j]=rand()%10;//random values in matrix
        }
    }
    
    printf("first matrix:\n");
    printMatrix(r1, c1, matrix);//1st call of the print function
    printf("\n");
    
    //same process as the 1st matrix
    int r2=3;
    int c2=3;

    int *matrix2=malloc((r2*c2)*(sizeof(int)));
    
    for (int i=0;i<r2;i++){
        for (int j=0;j<c2;j++){
            matrix2[(i*c2)+j]=rand()%10;
        }
    }
    printf("second matrix:\n");
    printMatrix(r2, c2, matrix2);//2nd call of the print function
    printf("\n");

    int *matrixRes = calloc(r1*c2, (sizeof(int)));//creating a 3rd matrix for results

    //time complexity : O(n^3) - standard matrix multiplication
    for (int i=0;i<r1;i++){
        for (int j=0;j<c2;j++){
            for (int k=0;k<c1;k++){//loops based on the multiplication (rows x columns) and the 3rd to secure that all the numbers of row1 and col2 are in the sum

                int index1=(i*c1)+k; //size of each row of the first matrix
                int index2=(k*c2)+j; //size of each column of the second matrix
                int indexRes=(i*c2)+j; //index of each sum
                matrixRes[indexRes] += matrix[index1] * matrix2[index2];//sum each product in the result positions

            }
        }
    }
    printf("result: \n\n");
    printMatrix(r1, c2, matrixRes);//3rd call of the function to print result

    //deallocating resources and terminating process safely
    free(matrix);
    free(matrix2);
    free(matrixRes);
    return 0;
}