#include<bits/stdc++.h>
using namespace std;

bool palin(string &s, int i){
    if(i>=s.length()/2) return true;

    if(s[i]!=s[s.length()-i-1]) return false;

   return palin(s,i+1);
}

int main(){
    int n = 4;
    string str = "abba";
    cout<<palin(str, 0);
    return 0;
}
