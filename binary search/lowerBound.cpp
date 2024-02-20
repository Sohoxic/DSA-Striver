
#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
    int ans;
    int low = 0;
    int high = n-1;

    while(low<=high){
        int mid = (low+high)/2;
        if(target>arr[mid]){
            low = mid+1;
        }
        else if(target<=a[mid]){
            ans = mid;
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    int ind = lowerBound(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}
