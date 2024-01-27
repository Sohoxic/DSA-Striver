#include<bits/stdc++.h>
using namespace std;
void solve(vector<string> &ans, int open, int close, string s){
    if(open==0 && close==0){
        ans.push_back(s);
        return;
    }
    if(open>0){
        s.push_back('(');
        solve(ans, open-1, close, s);
        s.pop_back();
    }
    if(close>open){
        s.push_back(')');
        solve(ans, open, close-1, s);
        s.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    int open = n, close = n;
    string output;
    solve(ans, open, close, output);
    return ans;
}

int main(){
    int n=3;
    vector<string> ans  = generateParenthesis(n);
    cout<<"[";
    for(auto it: ans){
        cout<<"\""<<it<<"\",";
    }    
    cout<<"]";
}