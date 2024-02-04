#include <bits/stdc++.h>
using namespace std;

// using Moore's voting algo
int majorityElement(vector<int> v) {
    int count = 0;
    int ele;
    for(int i=0;i<v.size();i++){
        if(count == 0){
            count = 1;
            ele = v[i];
        }
        else if(v[i]==ele){
            count++;
        }
        else{
            count--;
        }
    }   
    int count2 = 0;
    for(auto it:v){
        if(it == ele){
            count2++;
        }
    }
    if(count2>(v.size()/2)){
        return ele;
    }

   return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}