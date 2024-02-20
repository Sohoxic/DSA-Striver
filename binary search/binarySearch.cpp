#include <bits/stdc++.h>
using namespace std;
// Iterative
int binarySearch(vector<int>& nums, int n, int target) {
    int low = 0;
    int high = n-1;
    
    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(target<nums[mid]){
            high = mid - 1;
        }
        else{
            low = low+1;
        }
    }
    return -1;
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int n = a.size();
    int ind = binarySearch(a, n, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
    return 0;
}

