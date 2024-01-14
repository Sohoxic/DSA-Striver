#include<bits/stdc++.h>
using namespace std;

void subseq(int index, vector<int>  ds, int a[], int n){
   if(index==n and ds.size()==n){
    for(auto it:ds)
        cout<<it<<" ";
    if(ds.size() == 0)
        cout<<"{}";
    cout<<endl;
    return;
   }
   // pick
   ds.push_back(a[index]);
   subseq(index+1, ds, a, n);
   ds.pop_back();
   // not pick
   subseq(index+1, ds, a, n);
}

int main(){
    int a[]  = {3,1,2};
    vector<int> emptyList;
    subseq(0, emptyList, a, 3);
    return 0;
}