#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;
        // left sorted
        if(arr[low]<=arr[mid]){
            ans = min(ans, arr[low]);
            // cout<<ans;
            low = mid + 1;
        }
        else{
            ans = min(ans, arr[mid]);
            // cout<<ans;
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findMin(arr);
    cout << "The minimum element is: " << ans << "\n";
    return 0;
}