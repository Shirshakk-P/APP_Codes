#include <stdio.h>


void main(){
    int size;
    scanf("%d/n", &size); 
    int mat[size][size];
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i==j){
                if(i==0){
                    int sum=0;
                    sum+=mat[i+1][j];
                    sum+=mat[i][j+1];
                    if(sum!=mat[i][j]){
                        printf("No");
                    }
                }
                else if(i==(size-1)){
                    int sum=0;
                    sum+=mat[i-1][j];
                    sum+=mat[i][j-1];
                    if(sum!=mat[i][j]){
                        printf("No");
                    }
                }
                else{
                    int sum=0;
                    sum+=mat[i-1][j];
                    sum+=mat[i][j-1];
                    sum+=mat[i+1][j];
                    sum+=mat[i][j+1];
                    if(sum!=mat[i][j]){
                        printf("No");
                    }
                    
                }
            }
        }
    }
    
    printf("Yes");
    
    
  
}