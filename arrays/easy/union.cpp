#include<bits/stdc++.h>
using namespace std;

// vector < int > FindUnion(int arr1[], int arr2[], int n, int m){
//     map <int, int> mpp;
//     vector < int > Union;
//     for(int i=0; i<n; i++){
//         mpp[arr1[i]]++;
//     }
//     for(int i=0; i<m; i++){
//         mpp[arr2[i]]++;
//     }
//     for(auto it: mpp){
//         Union.push_back(it.first);
//     }
//     return Union;
// }

//  Optimisation 1: use set

// Optimisation 2:
vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  int i = 0, j = 0; 
  vector < int > Union; 
  while(i<n && j<m){
    if(arr1[i]<arr2[j]){
        if(Union.empty() || Union.back()!=arr1[i]){
            Union.push_back(arr1[i]);
        }
        i++;
    }
    else{
        if(Union.empty() || Union.back()!=arr2[i]){
            Union.push_back(arr2[j]);
        }
        j++;
    }
  }

  while(i<n){
    if(arr1[i]!=Union.back()){
        Union.push_back(arr1[i]);
    }
    i++;
  }

  while(j<m){
    if(arr2[j]!= Union.back()){
        Union.push_back(arr2[j]);
    }
    j++;
  }
  
  return Union;
}

int main() {
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12};
  vector < int > Union = FindUnion(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}
