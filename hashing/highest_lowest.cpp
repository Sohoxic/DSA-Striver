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
    int minFreq = INT_MAX, maxFreq = 0;
    int minEle = 0, maxEle =  n;
    for(int i=0;i<n;i++){
        long long int count = 1;
        if(visited[i]==true)
            continue;
        for(int j=i+1; j<n; j++){
            if(a[i]==a[j]){
                visited[j] = true;
                count++;
            }
        }
        if(count>maxFreq){
            maxEle = a[i];
            maxFreq = count;
        }
        if(count<minFreq){
            minEle = a[i];
            minFreq = count;
        }
    }
    cout << "The highest frequency element is: " << maxEle << "\n";
    cout << "The lowest frequency element is: " << minEle << "\n";
}

int main(){
    int arr[] = {10,5,10,15,10,5};                
    int n = sizeof(arr) / sizeof(arr[0]);
    freq(arr,n);
    return 0;
}