class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(), wordDict.end());
        return solve(0,st, s);
    }  

    bool solve(int index, set<string> st, string s){
        if(s.size() == index)   return true;
        string temp;
        for(int i=index; i<s.size(); i++){
            temp+=s[i];
            if(st.find(temp)!=st.end()){
                return solve(i+1, st, s);
            }
        }
        return false;
    }
};