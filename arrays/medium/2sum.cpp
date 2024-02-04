#include <bits/stdc++.h>
using namespace std;

// vector<int> twoSum(int n, vector<int> &arr, int target) {
//     map<int, int> mpp;
//     for(int i=0; i<n; i++){
//         int rem = target - arr[i];
//         if(mpp.find(rem)!=mpp.end()){
//             return {i,mpp[rem]};
//         }
//         mpp[arr[i]] = i;
//     }

//     return {-1,-1};
// }

//  Optimised approach: using 2 pointers
string twoSum(int n, vector<int> &a, int target) {
    sort(a.begin(), a.end());
    int left = 0, right = n-1;
    while(left<right){
        if(target == a[left] + a[right]){
            return "YES";
        }
        else if(a[left]+a[right]<target){
            left++;
        }
        else{
            right--;
        }
    }
    return "NO";
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    string ans = twoSum(n, arr, target);
    cout << ans<< endl;
    return 0;
}