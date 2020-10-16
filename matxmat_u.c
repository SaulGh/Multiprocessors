#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int main(){
    FILE *fptr0;
    fptr0=fopen("matrix_u.txt","w");
    int n = 40;
    int matrix[n-1][n-1];
    float matrix2[n-1][n-1];
    int i,j,k;
    float t1, t2, tf;
    t1 = omp_get_wtime();
    
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            matrix[i][j]=1.0;
        }
    }
    
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j+=2){
            matrix2[i][j]=0;
            for (k = 0; k < n; k++){
                matrix2[i][j]=(matrix[i][k]*matrix[k][j])+matrix2[i][j];
            }
        }
        for (j = 0; j < n; j+=2){
            matrix2[i][j+1]=0;
            for (k = 0; k < n; k++){
                matrix2[i][j+1]=(matrix[i][k]*matrix[k][j+1])+matrix2[i][j+1];
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            fprintf(fptr0, "%f ",matrix2[i][j]);
        }
        fprintf(fptr0, "\n");
    }
    t2 = omp_get_wtime();
    tf = t2 - t1;
    printf("Tiempo: (%f) segundos \n", tf);
    fclose(fptr0);
    return 0;
}