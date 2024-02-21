#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(target>=arr[mid]){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr= {1,2,2,3,4,5};
    int target = 2;
    int ans = upperBound(arr, target);
    cout<<ans;
    return 0;
}