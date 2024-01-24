#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int a[], int i, int n) {
    if(i == n)  return ;
    int j = i;
    while(j>0 && a[j-1]>a[j]){
        swap(a[j-1],a[j]);
        j--;
    }
    insertion_sort(a,i+1,n);
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using insertion Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertion_sort(arr, 0, n);

    cout << "After Using insertion Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
