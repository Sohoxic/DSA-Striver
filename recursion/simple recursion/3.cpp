#include<bits/stdc++.h>
using namespace std;

void reverseArray(int a[], int i, int n){
    if(i>=n/2) return;
    swap(a[i], a[n-i-1]);
    reverseArray(a,i+1,n);
}

int main(){
    int n = 4;
    int arr[] = {1,2,3,7};
    reverseArray(arr, 0, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<< " " ;
    }
    return 0;
}

