#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> update_matrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> distances(rows, vector<int>(cols, INT_MAX));
        queue<pair<int, int>> to_visit;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    distances[i][j] = 0;
                    to_visit.push({i, j});
                }
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!to_visit.empty()) {
            auto [current_row, current_col] = to_visit.front();
            to_visit.pop();

            for (const auto& [d_row, d_col] : directions) {
                int new_row = current_row + d_row;
                int new_col = current_col + d_col;

                if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols) {
                    if (distances[new_row][new_col] > distances[current_row][current_col] + 1) {
                        distances[new_row][new_col] = distances[current_row][current_col] + 1;
                        to_visit.push({new_row, new_col});
                    }
                }
            }
        }

        return distances;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> result = solution.update_matrix(mat);

    for (const auto& row : result) {
        for (int distance : row) {
            cout << distance << " ";
        }
        cout << endl;
    }

    return 0;
}
