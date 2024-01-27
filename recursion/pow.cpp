#include<bits/stdc++.h>
using namespace std;

int pow(int x, int n){
    double ans = 1.0;
    long long nn = n;
    if(nn<0)    nn*=-1;
    while(nn){
        if(nn%2){
            ans*=x;
            nn = nn-1;
        }
        else{
            x = (x*x);
            nn/=2;
        }
    }
    if(n<0) return double(1.0)/ans;
    return ans;
}

int main(){
    int x=2, n=10;
    cout<<pow(x,n); 
}