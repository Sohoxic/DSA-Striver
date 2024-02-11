// // Brute Force
// #include <bits/stdc++.h>
// using namespace std;

// int nCr(int n, int r) {
//     long long res = 1;

//     // calculating nCr:
//     for (int i = 0; i < r; i++) {
//         res = res * (n - i);
//         res = res / (i + 1);
//     }
//     return (int)(res);
// }

// vector<vector<int>> pascalTriangle(int n) {
//     vector<vector<int>> ans;

//     for (int row = 1; row <= n; row++) {
//         vector<int> tempLst; // temporary list
//         for (int col = 1; col <= row; col++) {
//             tempLst.push_back(nCr(row - 1, col - 1));
//         }
//         ans.push_back(tempLst);
//     }
//     return ans;
// }

// int main()
// {
//     int n = 5;
//     vector<vector<int>> ans = pascalTriangle(n);
//     for (auto it : ans) {
//         for (auto ele : it) {
//             cout << ele << " ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row) {
    int ans =1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int i = 1; i<row; i++){
        ans *= row-i;
        ans /= i;
        ansRow.push_back(ans);
    }
    
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;
    for(int i=1; i<=n; i++){
        vector<int> temp = generateRow(i);
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}
