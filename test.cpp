#include "bits/stdc++.h"
using namespace std;
#define ll int64_t

void dfs(string node, string parent, unordered_map<string, set<string>> &adj, map<string, int> &count)
{
    for (auto &x : adj[node])
    {
        if (x == parent)
            continue;
        dfs(x, node, adj, count);
        count[node] += count[x];
    }
    count[node]++;
}

vector<string> splitter(string &str)
{
    // split the string by ' '
    // use stringstream to split the string
    stringstream ss(str);
    string word;
    vector<string> ans;
    while (ss >> word)
    {
        ans.push_back(word);
    }
    return ans;
}

vector<int> getSubFolders(vector<vector<string>> existingStructureEdges, vector<string> queries)
{
    vector<int> ans;
    unordered_map<string, set<string>> adj;
    for (auto &x : existingStructureEdges)
    {
        adj[x[0]].insert(x[1]);
        adj[x[1]].insert(x[0]);
    }
    map<string, int> count;
    for (auto &x : queries)
    {
        auto query = splitter(x);
        if (query[0] == "mkdir")
        {
            adj[query[1]].insert(query[2]);
            adj[query[2]].insert(query[1]);
        }
        else if (query[0] == "count_subdir")
        {
            dfs("folder-1", "", adj, count);
            ans.push_back(count[query[1]]);
            count.clear();
        }
        else
        {
            for (auto &x : adj[query[1]])
            {
                adj[x].erase(query[1]);
            }
            adj.erase(query[1]);
        }
    }
    return ans;
}
int main()
{
    {
        vector<vector<string>> existingStructureEdges = {{"folder-2", "folder-1"}, {"folder-2", "folder-3"}, {"folder-2", "folder-4"}};
        vector<string> queries = {"mkdir folder-1 folder-5", "count_subdir folder-2", "count_subdir folder-1"};
        vector<int> ans = getSubFolders(existingStructureEdges, queries);
        for (auto &x : ans)
        {
            cout << x << endl;
        }
    }
    {
        vector<vector<string>> existingStructureEdges = {{"folder-1", "a"}, {"folder-1", "b"}, {"folder-1", "c"}, {"a", "d"}, {"a", "e"}, {"e", "f"}, {"c", "g"}};
        vector<string> queries = {"mkdir d h", "rmdir e", "count_subdir a"};
        vector<int> ans = getSubFolders(existingStructureEdges, queries);
        for (auto &x : ans)
        {
            cout << x << endl;
        }
    }
}
