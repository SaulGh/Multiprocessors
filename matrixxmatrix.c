#include <stdlib.h>
#include <stdio.h>

int main(){
    FILE *fptr1;
    
    int n = 10;
    int matrix[n-1][n-1];
    int i,j,k;

    fptr1=fopen("Matrix1.txt","w");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            matrix[i][j]=1.0;
        }
        
    }
    float r = 15.1;
    float matrix2[n-1][n-1];
    for (j = 0; j < n-1; j++)
    {
        for (i = 0; i < n; i++)
        {
            matrix2[i][j]=0;
            for (k = 0; k < n; k++)
            {
                matrix2[i][j]+=(matrix[i][k]*matrix[k][j]);
            }
            
        }
        
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            fprintf(fptr1,"%f ",matrix2[i][j]);
        }
        fprintf(fptr1,"\n");
    }

    fclose(fptr1);
    return 0;
}