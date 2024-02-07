


#include<bits/stdc++.h>
using namespace std;

vector<int> printLeaders(int arr[], int n) {

  vector<int> ans;
  int maxi = arr[n-1];
  ans.push_back(maxi);

  for(int i=n-2; i>=0; i--){
    if(arr[i]>maxi){
        maxi = arr[i];
        ans.push_back(maxi);
    }
  }
  
  return ans;
}

int main() {
    
  // Array Initialization.
  int n = 6;
  int arr[n] = {10, 22, 12, 3, 0, 6};

  vector<int> ans = printLeaders(arr,n);
  
  
  for(int i = ans.size()-1;i>=0;i--){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  return 0;
}
