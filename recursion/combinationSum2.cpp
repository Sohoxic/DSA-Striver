#include<bits/stdc++.h>
using namespace std;

void findCombination(int index, int target, vector<int> &a, vector<vector<int>> &ans, vector<int> &ds){
    if(target == 0){
        ans.push_back(ds);
        return;
    }

    for(int i=index; i< a.size(); i++){
        if(a[i]>target) break;
        if(i>index && a[i]==a[i-1]) continue;
        ds.push_back(a[i]);
        findCombination(i+1, target-a[i], a, ans, ds);
        ds.pop_back();
    }
}

vector<vector<int>> findCombination2(vector<int> v, int target){
    sort(v.begin(), v.end());
    vector < vector < int >> ans;
    vector < int > ds;
    findCombination(0, target, v, ans, ds);
    return ans;
}

int main(){
    vector<int> v{10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ans = findCombination2(v, target);
    for(auto v:ans){
        for(auto it:v){
            cout<<it<<",";
        }
        cout<<endl;
    }
}