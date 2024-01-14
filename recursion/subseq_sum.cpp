#include<bits/stdc++.h>
using namespace std;

void subseq(int index, vector<int>  ds, int a[], int s, int sum, int n){
   if(index==n){
    if( s == sum){
        for(auto it:ds)
            cout<<it<<" ";
        cout<<endl;
    }
    return;
   }
   
   // pick
   ds.push_back(a[index]);
   s+=a[index];
   subseq(index+1, ds, a, s, sum, n);
   s-=a[index];
   ds.pop_back();
   // not pick
   subseq(index+1, ds, a, s, sum, n);
}

int main(){
    int a[]  = {1,2,1};
    vector<int> emptyList;
    int sum =  2, s = 0;
    subseq(0, emptyList, a, s, sum, 3);
    return 0;
}