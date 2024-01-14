#include<bits/stdc++.h>
using namespace std;

void subsetSum(int index, vector<int> &v, vector<int> &ans, int n, int sum){
    if(index == n){
        ans.push_back(sum);
        return;
    }

    sum+=v[index];
    subsetSum(index+1, v, ans, n, sum);
    sum-=v[index];
    subsetSum(index+1, v, ans, n, sum);
}

vector<int> subsetSums(vector<int> &v, int n){
    // cout<<"hi";
    vector<int> ans;
    subsetSum(0, v, ans, n, 0);
    // for(auto it:ans){
    //     cout<<it;
    // }
    sort(ans.begin(), ans.end());
    // for(auto it:ans){
    //     cout<<it;
    // }
    return ans;
}

int main(){
    vector < int > arr{3,1,2};
    vector < int > ans = subsetSums(arr, arr.size());
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}