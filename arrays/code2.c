
#include <stdio.h>

int main(){
    int size=5;
    // scanf("%d/n", &size); 
    
    
    int mat[5][5] = {
    {3, 2, 0, 4, 5},
    {1, 10, 4, -2, 6},
    {0, 3, 7, 0, 8},
    {6, 5, 1, 4, 4},
    {9, 7, 0, -1, 3}
};
    
    int ind=-1;
    int maxSum=-10000;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i==j){
                if(i==0){
                    int sum = 0;
                    sum+=mat[i][j+1];
                    sum+=mat[i+1][j];
                    sum+=mat[i+1][j+1];
                    if(sum>maxSum){
                        maxSum=sum;
                        ind=i;
                    }
                    printf("%d: %d\n",mat[i][j],sum);
                }
                else if(i==(size-1)){
                    int sum = 0;
                    sum+=mat[i-1][j];
                    sum+=mat[i][j-1];
                    sum+=mat[i-1][j-1];
                    if(sum>maxSum){
                        maxSum=sum;
                        ind=i;
                    }
                    printf("%d: %d\n",mat[i][j],sum);
                }
                else{
                    int sum=0;
                    for(int a=i-1;a<=i+1;a++){
                        for(int b=j-1;b<=j+1;b++){
                            if(a==i && b==j){
                                continue;
                            }
                            sum+=mat[a][b];
                        }
                    }
                    if(sum>maxSum){
                        maxSum=sum;
                        ind=i;
                    }
                    printf("%d: %d\n",mat[i][j],sum);
                }
            }
        }
    }
    
    printf("index : %d",ind);
    
    return 0;
}
