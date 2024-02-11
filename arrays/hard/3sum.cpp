// find triplets that add upto zero
// brute
// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> triplet(int n, vector<int> &arr) {
//     set<vector<int>> st;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             for(int k=j+1;k<n;k++){
//                 if(arr[i]+arr[j]+arr[k] == 0){
//                     vector<int> temp = {arr[i], arr[j], arr[k]};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//             }
//         }
//     }
    
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }


// int main()
// {
//     vector<int> arr = { -1, 0, 1, 2, -1, -4};
//     int n = arr.size();
//     vector<vector<int>> ans = triplet(n, arr);
//     for (auto it : ans) {
//         cout << "[";
//         for (auto i : it) {
//             cout << i << " ";
//         }
//         cout << "] ";
//     }
//     cout << "\n";
//     return 0;
// }

// better approach




#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr) {
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for(int j=i+1; j<n; j++){
            int k = -(arr[i]+arr[j]);
            if(hashset.find(k)!=hashset.end()){
                vector<int> temp = {arr[i], arr[j], k};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    //store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
