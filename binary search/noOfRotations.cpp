#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        // both side sorted, that is entire array is sorted
        if(arr[low]<=arr[high]){
            index = low;
            ans = min(ans, arr[low]);
            break;
        }
        // left sorted
        if(arr[low]<=arr[mid]){
            if(arr[low]<ans){
                index = low;
                ans = arr[low];
            }
            // cout<<ans;
            low = mid + 1;
        }
        else{
           if(arr[mid]<ans){
                index = mid;
                ans = arr[low];
            }
            // cout<<ans;
            high = mid - 1;
        }
    }
    return index;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findMin(arr);
    cout << "The number of rotation is: " << ans << "\n";
    return 0;
}