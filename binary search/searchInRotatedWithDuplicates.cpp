// same as search in rotated array, but now the array has duplicate elements.

#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int n, int target) {
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[low] == arr[mid] && arr[mid]==arr[high]){
            low++;
            high--;
        }
        // left is sorted
        if(arr[low]<=arr[mid]){
            if(target>=arr[low] && target<=arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(target>=arr[mid] && target<=arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

    }

    return -1;
}

int main()
{
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int n = 9, target = 1;
    int ans = search(arr, n, target);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}

