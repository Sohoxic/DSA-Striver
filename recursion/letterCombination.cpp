#include<bits/stdc++.h>
using namespace std;

void DFS(vector<string> &ans, string &path, string digits, int pos, vector<string> letters){
    if(pos == digits.length()){
        ans.push_back(path);
        return;
    }
    for(auto c: letters[digits[pos]-'0']){
        path.push_back(c);
        DFS(ans, path, digits, pos+1, letters);
        path.pop_back();
    }
}

vector<string> letterCombo(string digits){
    vector<string> ans;
    string path= "";
    vector<string> letters ({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
    DFS(ans, path, digits, 0, letters);
    return ans;
}


int main(){
    string digits = "23"; // expected O/P = ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    vector<string> ans = letterCombo(digits);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}