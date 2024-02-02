#include<bits/stdc++.h>
using namespace std;

 bool searchNext(vector<vector<char>> &board, string word, int row, int col, int index, int m, int n) {
    if(index == word.length()){
        return true;
    }
    // checking all boundary conditions and invalid conditions
    if (row < 0 || col < 0 || row == m || col == n || board[row][col] != word[index] or board[row][col] == '!')
            return false;

    char c = board[row][col];
    board[row][col] = '!';
    
    bool top = searchNext(board, word, row-1, col, index+1,  m, n);
    bool right = searchNext(board, word, row, col + 1, index + 1, m, n);
    bool bottom = searchNext(board, word, row + 1, col, index + 1, m, n);
    bool left = searchNext(board, word, row, col - 1, index + 1, m, n);

    return top | right | bottom | left;
}

bool exist(vector<vector<char>> board, string word) {
    int row = board.size();
    int col = board[0].size();
    int index = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(board[i][j]==word[index]){
                if(searchNext(board, word, i, j, index, row, col)){
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board {{'A','B','C','E'},
                                {'S','F','C','S'},
                                {'A','D','E','E'}};
    string word = "ABCCED";
    bool res = exist(board, word);
    if(res==1)
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
}
