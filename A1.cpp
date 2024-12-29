
// Find Center of Star Graph

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int find_center(vector<vector<int>>& edges) {
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        }
        return edges[0][1];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> edges1 = {{1, 2}, {2, 3}, {4, 2}};
    vector<vector<int>> edges2 = {{1, 3}, {3, 2}, {3, 4}};

    int result1 = solution.find_center(edges1);
    int result2 = solution.find_center(edges2);

    cout << "Result 1 : " << result1 << endl;
    cout << "Result 2 : " << result2 << endl;

    return 0;
}