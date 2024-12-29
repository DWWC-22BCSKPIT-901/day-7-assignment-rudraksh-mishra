#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> accounts_merge(vector<vector<string>>& accounts) {
        unordered_map<string, string> email_to_name;
        unordered_map<string, string> parent;

        for (const auto& account : accounts) {
            string name = account[0];
            for (size_t i = 1; i < account.size(); i++) {
                if (parent.find(account[i]) == parent.end()) {
                    parent[account[i]] = account[i];
                }
                email_to_name[account[i]] = name;
                union_sets(account[1], account[i], parent);
            }
        }

        unordered_map<string, unordered_set<string>> unions;
        for (const auto& [email, _] : email_to_name) {
            string root = find(email, parent);
            unions[root].insert(email);
        }

        vector<vector<string>> merged_accounts;
        for (const auto& [root, emails] : unions) {
            vector<string> account(emails.begin(), emails.end());
            sort(account.begin(), account.end());
            account.insert(account.begin(), email_to_name[root]);
            merged_accounts.push_back(account);
        }

        return merged_accounts;
    }

private:
    string find(const string& email, unordered_map<string, string>& parent) {
        if (parent[email] != email) {
            parent[email] = find(parent[email], parent);
        }
        return parent[email];
    }

    void union_sets(const string& email1, const string& email2, unordered_map<string, string>& parent) {
        string root1 = find(email1, parent);
        string root2 = find(email2, parent);
        if (root1 != root2) {
            parent[root1] = root2;
        }
    }
};

int main() {
    Solution solution;
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"John", "johnnybravo@mail.com"},
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"Mary", "mary@mail.com"}
    };

    vector<vector<string>> result = solution.accounts_merge(accounts);

    for (const auto& account : result) {
        for (const auto& email : account) {
            cout << email << " ";
        }
        cout << endl;
    }

    return 0;
}
