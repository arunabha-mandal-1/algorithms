// 0/1 knapsack problem

#include <stdio.h>
#include <stdlib.h>

// utility function
int max(int a, int b){
    return (a>b)?a:b;
}

int* knapsack01(int* profitArr, int* weightArr, int size, int capacity){
    int k[size+1][capacity+1];
    for(int i=0; i<=size; i++){
        for(int w=0; w<=capacity; w++){
            if(i==0 || w==0){
                k[i][w]=0;
            }else if(weightArr[i-1]<=w){
                k[i][w]=max(profitArr[i-1] + k[i-1][w - weightArr[i-1]],
                            k[i-1][w]);
            }else{
                k[i][w]=k[i-1][w];
            }
        }
    }

    // print k
    printf("k : \n");
    for(int i=0; i<=size; i++){
        for(int w=0; w<=capacity; w++){
            printf("%d ", k[i][w]);
        }
        printf("\n");
    }

    printf("Maximum profit : %d\n", k[size][capacity]);
    int i = size;
    int j = capacity;
    int* resultVec = (int*)calloc(size-1, sizeof(int));
    while(i>0 && j>0){
        if(k[i][j]==k[i-1][j]){
            resultVec[i-1] = 0;
            i--;
        }else{
            resultVec[i-1]=1;
            i--;
            j=j-weightArr[i];
        }
    }
    return resultVec;
}
int main(){
    int profitArr[] = {1, 2, 5, 6};
    int weightArr[] = {2, 3, 4, 5};
    int size = sizeof(profitArr)/sizeof(profitArr[0]);
    int capacity = 8;

    int* resultVec = knapsack01(profitArr, weightArr, size, capacity);
    printf("Result vector : ");
    for(int i=0; i<size; i++){
        printf("%d ", resultVec[i]);
    }
    printf("\n");

    return 0;
}