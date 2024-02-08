#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> setMatrix(vector<vector<int>> &matrix, int row, int col, int m, int n){
    // row
    for(int i=0; i<m; i++){
        if(matrix[i][col]!=0){
            matrix[i][col] = -1;
        }
    }
    // column
    for(int j=0; j<n; j++){
        if(matrix[row][j]!=0){
            matrix[row][j] = -1;
        }
    }

    return matrix;
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 0){
                matrix = setMatrix(matrix, i, j, m, n);
            }
        }
    }


    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}
int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int m = matrix.size();
    int n = matrix[0].size();
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