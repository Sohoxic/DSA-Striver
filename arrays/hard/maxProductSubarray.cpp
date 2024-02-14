// #include<bits/stdc++.h>
// using namespace std;

// int maxProductSubArray(vector<int>& nums) {
//     int result = INT_MIN;
//     for(int i=0;i<nums.size()-1;i++) {
//         int prod = nums[i];
//         for(int j=i+1;j<nums.size();j++) {
//             prod *= nums[j];
//             result = max(result,prod);    
//         }
//     }
//     return result;
// }

// int main() {
//     vector<int> nums = {1,2,-3,0,-4,-5};
//     cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
//     return 0;
// }

//  Optimal



#include <bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int> &arr) {
    int n = arr.size(); //size of array.
    int ans = INT_MIN;
    int pre = 1, post = 1;
    for (int i = 0; i < n; i++) {
        if(pre==0)  pre = 1;
        if(post==0) post = 1;

        pre*= arr[i];
        post*= arr[n-i-1];
        ans = max(ans, max(pre, post));
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray is: "
         << maxProductSubArray(arr) << "\n";
    return 0;
}
