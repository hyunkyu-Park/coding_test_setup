#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rotateMatrix90(vector<vector<int>>& board) {
    int N = board.size();
    vector<vector<int>> newBoard(N, vector<int>(N));

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            newBoard[c][N - 1 - r] = board[r][c];
        }
    }

    return newBoard;
}

vector<vector<int>> rotateMatrix180(vector<vector<int>>& board) {
    int N = board.size();
    vector<vector<int>> newBoard(N, vector<int>(N));

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            newBoard[N - 1 - r][N - 1 - c] = board[r][c];
        }
    }

    return newBoard;
}

vector<vector<int>> rotateMatrix270(vector<vector<int>>& board) {
    int N = board.size();
    vector<vector<int>> newBoard(N, vector<int>(N));

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            newBoard[N - 1 - c][r] = board[r][c];
        }
    }

    return newBoard;
}

int main() {
    vector<vector<int>> board = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> rotated90 = rotateMatrix90(board);

    cout << "Rotated 90 degrees:" << endl;
    for (const auto& row : rotated90) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    vector<vector<int>> rotated180 = rotateMatrix180(board);

    cout << "Rotated 180 degrees:" << endl;
    for (const auto& row : rotated180) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    vector<vector<int>> rotated270 = rotateMatrix270(board);

    cout << "Rotated 270 degrees:" << endl;
    for (const auto& row : rotated270) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
