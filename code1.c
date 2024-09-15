#include<stdio.h>

void main(){
    int size;
    scanf("%d/n", &size); 
    int arr[size];
    int sum =0;
    for(int i=0;i<size;i++){
        scanf("%d",arr[i]);
        sum+=arr[i];
    }
    int k = (size*size)-size;
    int x = sum/k;

    int mat[size][size];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(i==j){
                mat[i][j]=arr[i];
            }
            else{
                mat[i][j]=x;
            }
            printf("%d ",mat[i][j]);
            /* code */
        }
        printf("/n");
        
        /* code */
    }
}