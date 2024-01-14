#include<bits/stdc++.h>
using namespace std;

class Solution{
    public: 
        void recurpermute(vector<int> &a, int n, vector<vector<int>> &ans, vector<int> &ds, int freq[]){
            if(ds.size() == n){
                ans.push_back(ds);
            }
            for(int i=0; i<n; i++){
                if(!freq[i]){
                    ds.push_back(a[i]);
                    freq[i]=1;
                    recurpermute(a,n,ans,ds,freq);
                    freq[i] = 0;
                    ds.pop_back();
                }
            }
        }

    public:
        vector<vector<int>> permute(vector<int> &v, int n){
            vector<vector<int>> ans;
            vector<int> ds;
            int freq[n] = {0};
            recurpermute(v,n, ans, ds, freq);
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