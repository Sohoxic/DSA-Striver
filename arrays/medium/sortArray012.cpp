
#include <bits/stdc++.h>
using namespace std;

// Dutch National flag algo (DNF)
void sortArray(vector<int>& a, int n) {

    int low = 0, mid = 0, high = n - 1; // 3 pointers
    while(mid<=high){
        if(a[mid]==0){
            swap(a[low],a[mid]);
            low++;
            mid++;
        }
        else if(a[mid]==1){
            mid++;
        }
        else{
            swap(a[mid],a[high]);
            high--;
        }
    }
}

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
