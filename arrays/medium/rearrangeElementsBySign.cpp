// It is given that number of positives and negatives are equal in number, else we have to use brute force.

#include<bits/stdc++.h>
using namespace std;

// Optimal solution
vector<int>RearrangebySign(vector<int> a){
    int n = a.size();
    // cout<<n;
    int positiveIndex=0, negativeIndex=1;
    vector<int> ans(n,0);
    for(int i = 0; i<n; i++){
        if(a[i]<0){
            ans[negativeIndex] = a[i];
            negativeIndex+=2;
        }
        else{
            ans[positiveIndex] = a[i];
            positiveIndex+=2;
        }
    }
    return ans;
}
int main() {
    
  vector<int> A = {1,2,-4,-5};
  vector<int> ans = RearrangebySign(A);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}