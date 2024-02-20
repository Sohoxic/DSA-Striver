#include <bits/stdc++.h>
using namespace std;
// Iterative
// int binarySearch(vector<int>& nums, int n, int target) {
//     int low = 0;
//     int high = n-1;
    
//     while(low<=high){
//         int mid = (low+high)/2;
//         if(nums[mid]==target){
//             return mid;
//         }
//         else if(target<nums[mid]){
//             high = mid - 1;
//         }
//         else{
//             low = low+1;
//         }
//     }
//     return -1;
// }

// Recursive
int search(vector<int>& nums, int n, int low, int high, int target) {
        int mid = (low+high)/2;
        if(low>high) return -1;
        if(nums[mid]==target){
            return mid;
        }
        else if(target<nums[mid]){
            return search(nums, n, low, mid - 1, target);
        }
        else{
            return search(nums, n, mid+1, high, target);
        }
}

int binarySearch(vector<int> nums,int target){
    int n = nums.size();
    int low = 0;
    int high = n-1;
    return search(nums, n, low, high, target);
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int n = a.size();
    int ind = binarySearch(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
    return 0;
}

