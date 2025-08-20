#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool issafe(vector<vector<char>>& board,int row,int col,char dig){
        for(int i=0;i<9;i++){
            if(board[row][i]==dig) return false;
            if(board[i][col]==dig) return false;
        }
        int sr=(row/3)*3;
        int sc=(col/3)*3;
        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(board[i][j]==dig) return false;
            }
        }
        return true;
    }

    bool solver(vector<vector<char>>& board,int row,int col){
        if(row==9) return true;

        int nextrow=row, nextcol=col+1;
        if(col==8){
            nextrow=row+1;
            nextcol=0;
        }

        if(board[row][col]!='.')
            return solver(board,nextrow,nextcol);

        for(char i='1'; i<='9'; i++){
            if(issafe(board,row,col,i)){
                board[row][col]=i;
                if(solver(board,nextrow,nextcol))
                    return true;
                board[row][col]='.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solver(board,0,0);
    }
};

// Function to print the board
void printBoard(vector<vector<char>>& board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution obj;
    cout << "Original Sudoku Board:\n";
    printBoard(board);

    obj.solveSudoku(board);

    cout << "\nSolved Sudoku Board:\n";
    printBoard(board);

    return 0;
}
