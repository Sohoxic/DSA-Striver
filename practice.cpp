#include <bits/stdc++.h>
using namespace std;

int partitioner(vector<int> &a, int low, int high){
    int pivot = a[low];
    int i = low;
    int j = high;
    while(i<j){
        while(a[i]<=pivot && i<high){
        i++;
        }
        while(a[j]>pivot && j>low){
            j--;
        }
        if (i<j)    swap(a[i], a[j]);
    }
    // cout<<pivot<<" "<<a[low]<<endl;
    swap(a[low], a[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high){
    if(low<high){
        int partitionIndex = partitioner(arr, low, high);
        qs(arr, low, partitionIndex-1);
        qs(arr, partitionIndex+1, high);
        }
}

vector<int> quickSort(vector<int> arr) {
    qs(arr, 0, arr.size() - 1);
    return arr;
}

int main()
{
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();
    cout << "Before Using quick Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = quickSort(arr);
    cout << "After Using quick sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}