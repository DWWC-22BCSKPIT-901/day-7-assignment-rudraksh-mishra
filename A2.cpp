#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool valid_path(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjacency_list(n);
        for (const auto& edge : edges) {
            adjacency_list[edge[0]].push_back(edge[1]);
            adjacency_list[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        queue<int> to_visit;
        to_visit.push(source);
        visited[source] = true;

        while (!to_visit.empty()) {
            int current = to_visit.front();
            to_visit.pop();

            if (current == destination) {
                return true;
            }

            for (int neighbor : adjacency_list[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    to_visit.push(neighbor);
                }
            }
        }

        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 0}};
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};

    bool result1 = solution.valid_path(3, edges1, 0, 2);
    bool result2 = solution.valid_path(6, edges2, 0, 5);

    cout << "Result 1 : " << (result1 ? "true" : "false") << endl;
    cout << "Result 2 : " << (result2 ? "true" : "false") << endl;

    return 0;
}