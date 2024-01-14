#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void findCombination(int index, int target, vector<int> &a, vector<vector<int>> &ans, vector<int> &ds){
            if(index == a.size()){
                if(target == 0){
                    ans.push_back(ds);
                }
                return;
            }
            if(a[index]<=target){
                ds.push_back(a[index]);
                findCombination(index, target-a[index], a, ans, ds);
                ds.pop_back();
            }
            findCombination(index+1, target, a, ans,  ds);
        }
    public:
        vector<vector<int>> combinationSum(vector<int> &a, int target){
            vector<vector<int>> ans;
            vector<int> ds;
            findCombination(0, target, a, ans, ds);
            return ans;
        }
};

int main(){
    Solution obj;
    vector<int> v {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans = obj.combinationSum(v, target);
    for(auto vector:ans){
        for(auto values: vector){
            cout<<values;
        }
        cout<<endl;
    }
    return 0;
}