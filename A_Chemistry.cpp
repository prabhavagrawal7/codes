#include <bits/stdc++.h>
using namespace std;

/*You are given an existing directory structure represented as a tree with n nodes and a series of g queries. The queries can be of three types:

mkdir <folder-x> <folder-y>: Create a folder named <folder-y> under <folder-x>.

rmdir <folder-x>: Delete <folder-x> from the system, including its subdirectories.

count_subdir <folder-x>: Compute the total number of folders (including both immediate and non-immediate) under <folder-x> and return the count.

Note: The directory named "folder-1" is always the root directory, and no query will call for it to be removed. You need to return an array of integers representing the results of the third type of query in the same order they are given.
*/
vector<vector<string>> parseQueries(vector<string> queries)
{
    vector<vector<string>> parsedQueries;
    for (string query : queries)
    {
        vector<string> parsedQuery;
        stringstream ss(query);
        string word;
        while (ss >> word)
        {
            parsedQuery.push_back(word);
        }
        parsedQueries.push_back(parsedQuery);
    }
    return parsedQueries;
}
void eraseSubFolders(map<string, set<string>> &existingStructure, string folder)
{
    for (auto &subFolder : existingStructure[folder])
    {
        eraseSubFolders(existingStructure, subFolder);
    }
    existingStructure.erase(folder);
}
vector<int> getSubFolders(vector<vector<string>> &existingStructureEdges, vector<string> queries)
{
    map<string, set<string>> existingStructure;
    map<string, string> parent;
    for (auto edge : existingStructureEdges)
    {
        existingStructure[edge[0]].insert(edge[1]);
        parent[edge[1]] = edge[0];
    }
    vector<vector<string>> parsedQueries = parseQueries(queries);
    vector<int> result;
    for (auto &query : parsedQueries)
    {
        if (query[0] == "mkdir")
        {
            existingStructure[query[1]].insert(query[2]);
            parent[query[2]] = query[1];
        }
        else if (query[0] == "rmdir")
        {
            eraseSubFolders(existingStructure, query[1]);
            existingStructure[parent[query[1]]].erase(query[1]);
        }
        else if (query[0] == "count_subdir")
        {
            int count = 0;
            queue<string> q;
            q.push(query[1]);
            while (!q.empty())
            {
                string currentFolder = q.front();
                q.pop();
                count++;
                for (auto &subFolder : existingStructure[currentFolder])
                {
                    q.push(subFolder);
                }
            }
            result.push_back(count);
        }
    }
    return result;
}
int main()
{
    /*
    existing structure:
    'folder-1', 'a'
    'folder-1', 'b'
    'folder-1', 'c'
    'a', 'd'
    'a', 'e'
    'e', 'f'
    'c', 'g'
    queries: 
    'mkdir', 'd', 'h'
    'rmdir', 'e'
    'count_subdir', 'a'
    */
    {
        vector<vector<string>> existingStructureEdges = {{"folder-1", "a"}, {"folder-1", "b"}, {"folder-1", "c"}, {"a", "d"}, {"a", "e"}, {"e", "f"}, {"c", "g"}};
        vector<string> queries = {"mkdir d h", "rmdir e", "count_subdir a"};
        vector<int> result = getSubFolders(existingStructureEdges, queries);
        for (auto &count : result)
        {
            cout << count << endl;
        }
    }

    /*
    existing structure:
    'folder-2', 'folder-4'
    'folder-2', 'folder-1'
    'folder-1', 'folder-3'
    queries:
    'count-subdir', 'folder-2'
    'count-subdir', 'folder-1'
    'count-subdir', 'folder-3'
    */
    {
        vector<vector<string>> existingStructureEdges = {{"folder-2", "folder-4"}, {"folder-2", "folder-1"}, {"folder-1", "folder-3"}};
        vector<string> queries = {"count_subdir folder-2", "count_subdir folder-1", "count_subdir folder-3"};
        vector<int> result = getSubFolders(existingStructureEdges, queries);
        for (auto &count : result)
        {
            cout << count << endl;
        }
    }
}



