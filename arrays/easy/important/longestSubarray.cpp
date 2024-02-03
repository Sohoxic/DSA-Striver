#include<bits/stdc++.h>
using namespace std;

// hashmap approach
// int getLongestSubarray(vector<int>& a, long long k){
//     int n = a.size();
//     map <long long, int> prefixSum;
//     int sum = 0;
//     int maxLen = 0;
//     for(int i=0; i<n; i++){
//         sum+=  a[i];
//         if(sum == k){
//             maxLen  =  max(maxLen,  i+1);
//         }    
//         if(prefixSum.find(sum-k)!=prefixSum.end()){
//             int len = i - prefixSum[sum-k];
//             maxLen = max(maxLen, len);
//         }
//         if(prefixSum.find(sum)==prefixSum.end()){
//             prefixSum[sum]=i;
//         }
//     }

//     return maxLen;
// }

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.
    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;

    while(right<n){
        while(left<=right && sum>k){
            sum-=a[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen, right-left+1);
        }
        right++;
        if(right<n) sum+=a[right];
    }

    return maxLen;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}