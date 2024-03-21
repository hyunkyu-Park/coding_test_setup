#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rotateMatrix90(vector<vector<int>>& matrix) {
    int row_length = matrix.size();
    int column_length = matrix[0].size();
    
    vector<vector<int>> result(column_length, vector<int>(row_length));
    for (int r = 0; r < row_length; ++r) {
        for (int c = 0; c < column_length; ++c) {
            result[c][row_length - 1 - r] = matrix[r][c];
        }
    }
    return result;
}

vector<vector<int>> rotateMatrix180(vector<vector<int>>& matrix) {
    int row_length = matrix.size();
    int column_length = matrix[0].size();
    
    vector<vector<int>> result(row_length, vector<int>(column_length));
    for (int r = 0; r < row_length; ++r) {
        for (int c = 0; c < column_length; ++c) {
            result[row_length - 1 - r][column_length - 1 - c] = matrix[r][c];;
        }
    }
    return result;
}

vector<vector<int>> rotateMatrix270(vector<vector<int>>& matrix) {
    int row_length = matrix.size();
    int column_length = matrix[0].size();
    
    vector<vector<int>> result(column_length, vector<int>(row_length));
    for (int r = 0; r < row_length; ++r) {
        for (int c = 0; c < column_length; ++c) {
            result[column_length - 1 - c][r] = matrix[r][c];
        }
    }
    return result;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    vector<vector<int>> rotated90 = rotateMatrix90(matrix);

    for (const auto& row : rotated90) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;
    vector<vector<int>> rotated180 = rotateMatrix180(matrix);

    for (const auto& row : rotated180) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;
    vector<vector<int>> rotated270 = rotateMatrix270(matrix);

    for (const auto& row : rotated270) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}








