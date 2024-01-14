#include<bits/stdc++.h>
using namespace std;

// int freq(int a[], int n){
//    unordered_map<int, int> mpp;
//    for(int i=0;i<n;i++){
//     mpp[a[i]]++;
//    }
//    for(auto i:mpp){
//     cout<<i.first<<" "<<i.second<<endl;
//    }
// }

int freq(int a[], int n){
    vector<bool> visited(n,false);
    
    for(int i=0;i<n;i++){
        int count = 1;
        if(visited[i]==true)
            continue;
        for(int j=i+1; j<n; j++){
            if(a[i]==a[j]){
                visited[j] = true;
                count++;
            }
        }
        cout<<a[i]<<" occurs "<<count<<" times.";
    }
}

int main(){
    int arr[] = {10,5,10,15,10,5};                
    int n = sizeof(arr) / sizeof(arr[0]);
    freq(arr,n);
    return 0;
}