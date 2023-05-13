// Fractional Knapsack Problem
#include <stdio.h>
#include <stdlib.h>

// utility function
// A = p/w vector
void merge(float* A, int low, int high, int mid, int* profitArr, int* weightArr){
    int i=low;
    int j=mid+1;
    int k=0;
    float* B=(float*)calloc(high-low+1, sizeof(float));
    int* auxProfit=(int*)calloc(high-low+1, sizeof(int));
    int* auxWeight=(int*)calloc(high-low+1, sizeof(int));
    while(i<=mid && j<=high){
        if(A[i]<A[j]){
            B[k]=A[i];
            auxProfit[k]=profitArr[i];
            auxWeight[k]=weightArr[i];
            i++;
            k++;
        }else{
            B[k]=A[j];
            auxProfit[k]=profitArr[j];
            auxWeight[k]=weightArr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        B[k]=A[i];
        auxProfit[k]=profitArr[i];
        auxWeight[k]=weightArr[i];
        i++;
        k++;
    }
    while(j<=high){
        B[k]=A[j];
        auxProfit[k]=profitArr[j];
        auxWeight[k]=weightArr[j];
        j++;
        k++;
    }
    for(int l=low, m=0; l<=high, m<k; l++, m++){
        A[l]=B[m];
        profitArr[l]=auxProfit[m];
        weightArr[l]=auxWeight[m];
    }
}

// utility function
void mergeSort(float* A, int low, int high, int* profitArr, int* weightArr){
    if(low<high){
        int mid=low+(high-low)/2;
        mergeSort(A,low, mid, profitArr, weightArr);
        mergeSort(A,mid+1, high, profitArr, weightArr);
        merge(A, low, high, mid, profitArr, weightArr);
    }
}

void fractionalKnapsack(int* profitArr, int* weightArr, int size, float capacity){
    float* pwArr = (float*)calloc(size, sizeof(float));
    float* resultVec = (float*)calloc(size, sizeof(float));
    for(int i=0; i<size; i++){
        resultVec[i] = 0.00;
    }
    float profit = 0.00;
    for(int i=0; i<size; i++){
        pwArr[i] = (float)profitArr[i]/(float)weightArr[i];
    }
    mergeSort(pwArr, 0, size-1, profitArr, weightArr);

    // p/w vector
    printf("p//w vector : ");
    for(int i=0; i<size; i++){
        printf("%0.3f ", pwArr[i]);
    }
    printf("\n");
    int i = size-1;
    for(;i>=0; i--){
        if(capacity>0 && weightArr[i]<=capacity){
            capacity = capacity - weightArr[i];
            profit = profit + (float)profitArr[i];
            resultVec[i] = 1;
        }else{
            break;
        }
    }
    if(capacity>0){
        profit = profit + profitArr[i]*(capacity/weightArr[i]);
        resultVec[i] = capacity/(float)weightArr[i];
    }
    printf("Maximum profit : %0.3f\n", profit);
    printf("Weight  Fraction\n");
    for(int i=0; i<size; i++){
        printf("%d      %f\n", weightArr[i], resultVec[i]);
    }
    // printf("\n");
}

int main(){
    int profitArr[] = {20, 25, 60};
    int weightArr[] = {2, 4, 8};
    float capacity = 12;
    int size = sizeof(profitArr)/sizeof(profitArr[0]);

    fractionalKnapsack(profitArr, weightArr, size, capacity);
    // printf("%d\n", profitArr[0]); // testing
    return 0;
}