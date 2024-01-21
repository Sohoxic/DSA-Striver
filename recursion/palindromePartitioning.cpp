#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector < vector < string >> partition(string s) {
      vector<vector<string>> ans;
      vector<string> path;
      partitionHelper(0,s, path, ans);

      return ans;
    }

  void partitionHelper(int index, string s, vector < string > & path, vector < vector < string > > & ans) {
        if(index == s.length()){
            ans.push_back(path);
            return;
        }
        for(int i = index; i<s.size(); i++){
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i-index+1));
                partitionHelper(i+1, s, path, ans);
                path.pop_back();
            }
        }
  }

  bool isPalindrome(string s, int start, int end) {
    while(start<=end){
        if(s[start++]!=s[end--])    return false;
    }
    return true;
  }
};

int main() {
  string s = "aabb";
  Solution obj;
  vector < vector < string >> ans = obj.partition(s);
  int n = ans.size();
  cout << "The Palindromic partitions are :-" << endl;
  cout << " [ ";
  for (auto i: ans) {
    cout << "[ ";
    for (auto j: i) {
      cout << j << " ";
    }
    cout << "] ";
  }
  cout << "]";

  return 0;
}