#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &a, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    int count = 0;
    while(left<=mid && right<=high){
        if(a[left] <= a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            right++;
            count+= (mid - left + 1);
        }
    }
    while (left <= mid) {
        temp.push_back(a[left]);
        left++;
    }

    
    while (right <= high) {
        temp.push_back(a[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        a[i] = temp[i - low];
    }

    return count; 
}

int mergeSort(vector<int> &a, int low, int high){
    int count = 0;
    int mid = (low+high)/2;
    if(low>=high) return count;
    count+= mergeSort(a,low, mid);
    count+= mergeSort(a, mid+1, high);
    count+= merge(a, low, mid, high);
    return count;
}

int numberOfInversions(vector<int> &a, int n){
    return mergeSort(a, 0, n-1);
}

int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = numberOfInversions(a, n);
    cout << "The number of inversions are: "
         << cnt << endl;
    return 0;
}