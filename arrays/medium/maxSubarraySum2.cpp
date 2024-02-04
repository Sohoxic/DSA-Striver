#include <bits/stdc++.h>
using namespace std;

// Optimised: Kadane's Algorithm
int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN;
    int sum = 0;
    int low=-1, high=-1;
    int start = 0;
    for(int i=0; i<n; i++){
        if(sum == 0)    start=i;
        sum += arr[i];

        if(sum<0){
            sum = 0;
        }
        if(maxi < sum){
            maxi = sum;
            low = start;
            high = i;
        }
    }

    for(int j=start; j<=high; j++){
        cout<<arr[j]<<" ";
    }
    cout<<endl;
    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}