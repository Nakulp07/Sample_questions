// Header Files
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

/*
 * num is number of cities in the state.
 * roadList is a list of roads where each road connects two cities.
 */

// Global variables for adjacency list and subtree sizes
const int MAXN = 100005;
vector<int> adj[MAXN];
vector<int> subtree_size(MAXN, 0);

// DFS to calculate the size of each subtree
int dfs(int city, int parent) {
    subtree_size[city] = 1; // Count the current city
    for (int neighbor : adj[city]) {
        if (neighbor != parent) {
            subtree_size[city] += dfs(neighbor, city);
        }
    }
    return subtree_size[city];
}

vector<int> maxTollRevenue(int num, vector<vector<int>> roadList) {
    // Initialize adjacency list from roadList
    for (auto road : roadList) {
        int u = road[0];
        int v = road[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Initialize subtree sizes with DFS
    dfs(1, -1);

    int max_toll = 0;
    vector<int> result = {INT_MAX, INT_MAX};

    // Iterate through each road
    for (auto road : roadList) {
        int u = road[0];
        int v = road[1];

        // Ensure u is the city with the larger subtree
        if (subtree_size[u] < subtree_size[v]) {
            swap(u, v);
        }

        int toll = subtree_size[v] * (num - subtree_size[v]);
        if (toll > max_toll || (toll == max_toll && make_pair(min(u, v), max(u, v)) < make_pair(result[0], result[1]))) {
            max_toll = toll;
            result = {min(u, v), max(u, v)};
        }
    }

    return result;
}

int main() {
    // Input for num
    int num;
    cin >> num;

    // Input for roadList
    int roadList_row = num ;
    int roadList_col = 2;

    vector<vector<int>> roadList(roadList_row, vector<int>(roadList_col));

    for (int idx = 0; idx < roadList_row; idx++) {
        for (int jdx = 0; jdx < roadList_col; jdx++) {
            cin >> roadList[idx][jdx];
        }
    }

    // Output
    vector<int> result = maxTollRevenue(num, roadList);
    for (int idx = 0; idx < result.size() - 1; idx++) {
        cout << result[idx] << " ";
    }
    cout << result[result.size() - 1];

    return 0;
}
