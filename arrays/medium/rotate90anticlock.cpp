// #include<bits/stdc++.h>
// using namespace std;

// void rotate(vector<vector<int>> matrix) {
//   int n = matrix.size();
//   vector<vector<int>> temp(n, vector<int> (n));

//   int ind = n - 1;
//   for (int i = 0; i < n; i++) {

//     for (int j = 0; j < n; j++) {
//       temp[i][j] = matrix[j][ind];
//     }
//     ind--;
//   }
//   //Printing array after rotation
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n; j++) {
//       cout << temp[i][j] << " ";
//     }
//     cout << endl;
//   }
// }
// int main() {
//   vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

//   rotate(matrix);

// }

// Optimal approach: Transpose and reverse Column

#include<bits/stdc++.h>

using namespace std;

void rotate(int matrix[][3]) {
  int n = 3;
    cout<<"original array"<<endl; 
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout<<endl;
  /* Finding transpose*/
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
    cout<<"after transpose"<<endl;
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout<<endl;

  /* Reverse every column */
  int ind = n - 1;
  for(int i=0; i<n; i++){
    for(int j=0; j<n/2; j++){
        int temp = matrix[j][i];
        matrix[j][i] = matrix[ind][i];
        matrix[ind][i] = temp;
        ind--;
    }
    ind = n-1;
  }

  //Printing array after rotation
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}
int main() {
  int matrix[][3] = {{1,2,3},{4,5,6},{7,8,9}};

  rotate(matrix);

}