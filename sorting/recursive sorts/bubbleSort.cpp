#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int a[], int n){
    if (n==1) return;
    int didswap = 0;
    for(int j=0;j<n-1;j++){
        if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
            didswap = 1;
        }
    }
    
    if(!didswap)    return;
    bubble_sort(a, n-1);
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;

    bubble_sort(arr, n);
    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;

}