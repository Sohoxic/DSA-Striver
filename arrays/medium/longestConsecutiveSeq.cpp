


// #include <bits/stdc++.h>
// using namespace std;

// int linearSearch(vector<int> a, int x){
//     for(int i=0; i<a.size(); i++){
//         if(x == a[i]){
//             return 1;
//         }
//     }
//     return 0;
// }

// int longestSuccessiveElements(vector<int> &a, int n){
//     int longest = 1;

//     for(int i=0; i<n; i++){
//         int x = a[i];
//         int count=1;
//         while(linearSearch(a, x+1)){
//             x++;
//             count++;
//         }
//         longest = max(longest, count);
//     }

//     return longest;
// }

// int main()
// {
//     vector<int> a = {100, 200, 1, 2, 3, 4};
//     int n = a.size();
//     int ans = longestSuccessiveElements(a, n);
//     cout << "The longest consecutive sequence is " << ans << "\n";
//     return 0;
// }


// better solution

// #include <bits/stdc++.h>
// using namespace std;

// int longestSuccessiveElements(vector<int>&a) {
//     int n = a.size();
//     if (n == 0) return 0;

//     //sort the array:
//     sort(a.begin(), a.end());
//     int longest = 1;
//     int count = 0;
//     int lastSmaller = INT_MIN;

//     for(int i=0; i<n; i++){
//         if(a[i] == lastSmaller+1){
//             count++;
//             lastSmaller = a[i];
//         }
//         else if(a[i] != lastSmaller){
//             count = 1;
//             lastSmaller = a[i];
//         }

//         longest = max(longest, count);
//     }

//     return longest;

// }

// int main()
// {
//     vector<int> a = {100, 200, 1, 2, 3, 4};
//     int ans = longestSuccessiveElements(a);
//     cout << "The longest consecutive sequence is " << ans << "\n";
//     return 0;
// }


// Optimal Solution




#include <bits/stdc++.h>
using namespace std;

int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}
