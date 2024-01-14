#include<bits/stdc++.h>
using namespace std;

bool subseq(int index, vector<int>  ds, int a[], int s, int sum, int n){
   if(index==n){
    if( s == sum){
        for(auto it:ds)
            cout<<it<<" ";
        return true;
    }
    return false;
   }
   // pick
   ds.push_back(a[index]);
   s+=a[index];
   if(subseq(index+1, ds, a, s, sum, n) == true){
    return true;
   }
   s-=a[index];
   ds.pop_back();
   // not pick
   if(subseq(index+1, ds, a, s, sum, n) == true){
    return true;
   }
   return false;
}

int main(){
    int a[]  = {1,2,1};
    vector<int> emptyList;
    int sum =  2, s = 0;
    subseq(0, emptyList, a, s, sum, 3);
    return 0;
}