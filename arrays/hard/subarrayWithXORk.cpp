// #include <bits/stdc++.h>
// using namespace std;

// int subarraysWithXorK(vector<int> a, int k) {
//     int n = a.size(); //size of the given array.
//     int cnt = 0;

//     // Step 1: Generating subarrays:
//     for (int i = 0; i < n; i++) {
//         int xorr = 0;
//         for (int j = i; j < n; j++) {
//             xorr = xorr ^ a[j];
//             if (xorr == k) cnt++;
//         }
//     }
//     return cnt;
// }

// int main()
// {
//     vector<int> a = {4, 2, 2, 6, 4};
//     int k = 6;
//     int ans = subarraysWithXorK(a, k);
//     cout << "The number of subarrays with XOR k is: "
//          << ans << "\n";
//     return 0;
// }

// Optimal Approach




#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int xr = 0;
    map<int, int> mpp; //declaring the map.
    mpp[xr]++; //setting the value of 0.
    int cnt = 0;

    for(int i=0; i<n; i++){
        xr^= a[i];
        int x = xr^k;

        cnt+= mpp[x];
        
        mpp[x]++;
    }

    return cnt;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}

