/*
 *
 * PROGRAMM MADE BY @1ABDESS
 * link to linear algebra THEORY:
 * https://en.wikipedia.org/wiki/Linear_algebra
 * https://en.wikipedia.org/wiki/Matrix_(mathematics)
 * https://www.math.tamu.edu/~dallen/m640_03c/lectures/chapter2.pdf
 *
*/
#include <stdio.h>
int dim; //global variable

void InsertMatrix(int m[][dim]){
    for(int i=0; i<dim; i++) {
        for (int z = 0; z < dim; z++) {
            printf("Cell [%d] [%d]:", (i+1), (z+1));
            scanf("%d", &m[i][z]);
        }
    }
}
void PrintMatrix(int m[][dim]){
    printf("\n----\nMatrix:\n");
    for(int i=0; i<dim; i++){
        for(int z=0; z<dim; z++){
            printf("[%d] ", m[i][z]);
        }
        printf("\n");
    }
}
int CalculateDet(int m[][dim]){
    if(dim == 2){
        //det matrix 2x2
        int det = ((m[0][0] * m[1][1]) - (m[0][1] * m[1][0]));
        return det;
    }
    if(dim == 3){
        //det matrix 3x3
        int det = ((m[0][0]*m[1][1]*m[2][2]) + (m[0][1]*m[1][2]*m[2][0]) + (m[0][2]*m[1][0]*m[2][1])) - ( (m[0][2]*m[1][1]*m[2][0]) + (m[0][1]*m[1][0]*m[2][2]) + (m[0][0]*m[1][2]*m[2][1]));
        return det;
    }
}
void IdentityMatrix(int m[][dim]){
    int h = (dim*dim)-dim;
    int countZeros = 0;
    int countOnes = 0;


    for(int i=0; i<dim; i++){
        for(int z=0; z<dim; z++){
            if(m[i][z] == 0){
                countZeros++;
            }
        }
    }
    for(int i=0; i<dim; i++){
        if(m[i][i] == 1){
            countOnes++;
        }
    }

    if( (countOnes == dim) && (countZeros == h) ){
        printf("\n[V] Identity matrix");
    }else{
        printf("\n[X] Identity matrix");
    }
}
void DiagonalMatrix(int m[][dim]){
    int h = (dim*dim)-dim;
    int countZeros = 0;
    int count = 0;

    for(int i=0; i<dim; i++){
        for(int z=0; z<dim; z++){
            if(m[i][z] == 0){
                countZeros++;
            }
        }
    }
    for(int i=0; i<dim; i++){
        if(m[i][i] != 0){
            count++;
        }
    }

    if( (count == dim) && (countZeros == h) ){
        printf("\n[V] Diagonal matrix");
    }else{
        printf("\n[X] Diagonal matrix");
    }

}

int main() {
    int s;
    printf("\t\tMatrix Program: ");
    printf("\nChoose Option: \n");
    printf("[0] Exit.\n");
    printf("[1] Matrix Determinant.\n");
    printf("[2] Matrix Type.\n\n");

    scanf("%d", &s);

    while(s != 0){
        if(s == 1){
            //Matrix Determinant
            int mat[dim][dim], det;

            printf("\nEnter the size of the square matrix (2<x<3): ");
            scanf(" %d", &dim);

            if(dim < 2 && dim > 3){
                printf("no.");
            }else{
                InsertMatrix(mat);
                PrintMatrix(mat);
                det = CalculateDet(mat);
                printf("\nDET = %d\n-------\n", det);
                s = 1;
            }
        }
        if(s == 2){
            //Matrix Type

            int mat[dim][dim];
            printf("\nEnter the size of the square matrix: ");
            scanf(" %d", &dim);

            InsertMatrix(mat);
            PrintMatrix(mat);

            printf("\nthe matrix is:");
            IdentityMatrix(mat);
            DiagonalMatrix(mat);

            s = 0;
        }
    }//end while

    return 0;
}