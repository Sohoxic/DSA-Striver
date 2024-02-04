
#include <bits/stdc++.h>
using namespace std;

// Better solution
// int maxSubarraySum(int a[], int n) {
//     int maxi = INT_MIN; // maximum sum

//     for (int i = 0; i < n; i++) {
//         int sum = 0;
//         for(int j=i; j<n; j++){
//             sum+=a[j];
//             maxi = max(sum, maxi);
//         }
//     }

//     return maxi;
// }

// Optimised: Kadane's Algorithm


int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum<0){
            sum = 0;
        }
        maxi = max(maxi, sum);
    }

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