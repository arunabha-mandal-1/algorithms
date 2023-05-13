// MAXIMUM SUBARRAY SUM PROBLEM
// ----------------------------

#include <stdio.h>
#include <limits.h>

int max(int a, int b){
    return (a>b)?a:b;
}

int maxSubarraySum(int* arr, int low, int high){
    if(low > high){
        return INT_MIN;
    }else if(low==high){
        return arr[low];
    }
    int mid = low + (high - low)/2;
    int left_sum = INT_MIN;
    int sum  = 0;
    for(int i=mid; i>=low; i--){
        sum = sum + arr[i];
        if(sum>left_sum){
            left_sum=sum;
        }
    }

    sum=0;
    int right_sum = INT_MIN;
    for(int i=mid+1; i<=high; i++){
        sum = sum + arr[i];
        if(sum>right_sum){
            right_sum = sum;
        }
    }

    int left_right_max = max(maxSubarraySum(arr, low, mid), maxSubarraySum(arr, mid+1, high));
    return max(left_sum + right_sum, left_right_max);
}

int main(){
    int arr[] = { -2, -5, 6, -2, -3, 1, 5, -6 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    printf("The maximum sum of the subarray is %d",
            maxSubarraySum(arr, 0, n - 1));
 
    return 0;
}