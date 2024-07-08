#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        int bracket = 0;
        string result;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                bracket++;
                if(bracket>1){
                    result+=s[i];
                }
            }
            else{
                // cout<<"hello";
                bracket--;
                if(bracket > 0){
                    result+=s[i];
                }
            }
        }

        return result;
    }
};

int main(){
    Solution sol;
    string result = sol.removeOuterParentheses("(()())(())");
    cout<<result;
    return 0;
}