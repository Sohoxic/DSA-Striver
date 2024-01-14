#include<bits/stdc++.h>
using namespace std;

class Solution{
    public: 
        void recurpermute(int index, vector<int> &a, int n, vector<vector<int>> &ans){
            if(index == n){
                ans.push_back(a);
                return;
            }
            for(int i=index; i<n; i++){
                swap(a[index],a[i]);
                recurpermute(index+1,a,n,ans);
                swap(a[index],a[i]);
            }
        }

    public:
        vector<vector<int>> permute(vector<int> &v, int n){
            vector<vector<int>> ans;
            vector<int> ds;
            int freq[n] = {0};
            recurpermute(0,v,n, ans);
            return ans;
        }
};

int main(){
    Solution obj;
    vector<int> v{1,2,3};
    vector < vector < int >> sum = obj.permute(v, v.size());
    cout << "All Permutations are " << endl;
    for (int i = 0; i < sum.size(); i++) {
      for (int j = 0; j < sum[i].size(); j++)
        cout << sum[i][j] << " ";
      cout << endl;
    }
}