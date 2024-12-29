#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int network_delay_time(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (const auto& time : times) {
            graph[time[0]].emplace_back(time[1], time[2]);
        }

        vector<int> min_time(n + 1, INT_MAX);
        min_time[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, k);

        while (!pq.empty()) {
            auto [current_time, node] = pq.top();
            pq.pop();

            if (current_time > min_time[node]) {
                continue;
            }

            for (const auto& [neighbor, weight] : graph[node]) {
                int new_time = current_time + weight;
                if (new_time < min_time[neighbor]) {
                    min_time[neighbor] = new_time;
                    pq.emplace(new_time, neighbor);
                }
            }
        }

        int result = *max_element(min_time.begin() + 1, min_time.end());
        return result == INT_MAX ? -1 : result;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4;
    int k = 2;

    int result = solution.network_delay_time(times, n, k);

    cout  << "Result : " << result << endl; 

    return 0;
}
