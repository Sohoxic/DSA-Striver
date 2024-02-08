// Brute Force

// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>> setMatrix(vector<vector<int>> &matrix, int row, int col, int m, int n){
//     // row
//     for(int i=0; i<m; i++){
//         if(matrix[i][col]!=0){
//             matrix[i][col] = -1;
//         }
//     }
//     // column
//     for(int j=0; j<n; j++){
//         if(matrix[row][j]!=0){
//             matrix[row][j] = -1;
//         }
//     }

//     return matrix;
// }

// vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int m, int n){
//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             if(matrix[i][j] == 0){
//                 matrix = setMatrix(matrix, i, j, m, n);
//             }
//         }
//     }


//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             if(matrix[i][j] == -1){
//                 matrix[i][j] = 0;
//             }
//         }
//     }

//     return matrix;
// }
// int main()
// {
//     vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
//     int m = matrix.size();
//     int n = matrix[0].size();
//     vector<vector<int>> ans = zeroMatrix(matrix, m, n);

//     cout << "The Final matrix is:";
//     for (auto it : ans) {
//         for (auto ele : it) {
//             cout << ele << " ";
//         }
//         cout <<endl;
//     }
//     return 0;
// }

// Better Approach


// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int m, int n) {

//     int row[m] = {0}; // row array
//     int col[n] = {0}; // col array

//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             if(matrix[i][j] == 0){
//                 row[i] = 1;
//                 col[j] = 1;
//             }
//         }
//     }   

//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             if(row[i] || col[j]){
//                 matrix[i][j] = 0;
//             }
//         }
//     }


//     return matrix;
// }

// int main()
// {
//     vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
//     int m = matrix.size();
//     int n= matrix[0].size();
//     vector<vector<int>> ans = zeroMatrix(matrix, m, n);

//     cout << "The Final matrix is: n";
//     for (auto it : ans) {
//         for (auto ele : it) {
//             cout << ele << " ";
//         }
//         cout << "n";
//     }
//     return 0;
// }

// Optimal Approach

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int m, int n) {

    int row[m] = {0}; // row array
    int col[n] = {0}; // col array
    int col0 = 1;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                if(j!=0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }   

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][j]!=0){if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }}
        }
    }

    if (matrix[0][0] == 0){
        for(int j=0; j<n; j++){
            matrix[0][j] == 0;
        }
    }

    if (col0 == 0){
        for(int i=0; i<n; i++){
            matrix[i][0] == 0;
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int m = matrix.size();
    int n= matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, m, n);

    cout << "The Final matrix is:";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout <<endl;
    }
    return 0;
}
