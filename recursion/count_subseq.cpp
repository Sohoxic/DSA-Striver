#include<bits/stdc++.h>
using namespace std;

int subseq(int index, int a[], int s, int sum, int n){
   if(index==n){
    if( s == sum){
        return 1;
    }
    return 0;
   }
   // pick
   s+=a[index];
   int l = subseq(index+1, a, s, sum, n);
   s-=a[index];
   // not pick
   int r = subseq(index+1, a, s, sum, n) == 1;

   return l+r;
}

int main(){
    int a[]  = {1,2,1};
    int sum =  3, s = 0;
    cout<<subseq(0, a, s, sum, 3);
    
    return 0;
}