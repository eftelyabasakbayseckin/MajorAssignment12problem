#include <iostream>
#include<vector>
using namespace std;

/*PROBLEM7: BACKTRACKING*/

class Solution {
public:
    bool isSafe(int id, bool graph[101][101], vector<int>& color, int n, int colr) {
        for (int j = 0; j < n; j++)
        {
            if (j != id && graph[j][id] == 1 && color[j] == colr)
            {
                return false;
            }
        }
        return true;
    }

    bool solve(int id, bool graph[101][101], vector<int>& color, int m, int n) {
        if (id == n)
        {
            return true;
        }
        for (int i = 1; i <= m; i++)
        {
            if (isSafe(id, graph, color, n, i))
            {
                color[id] = i;
                if (solve(id + 1, graph, color, m, n))
                {
                    return true;
                }
                color[id] = 0;
            }
        }
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> color(n, 0);
        if (solve(0, graph, color, m, n))
        {
            return true;
        }
        return false;
    }
};

int main() {
    int N = 3;
    int M = 2;
    int E = 3;
    pair<int, int> Edges[] = { {0,1},{1,2},{0,2} };

    bool graph[101][101] = { false };
    for (int i = 0; i < E; i++) {
        int u = Edges[i].first;
        int v = Edges[i].second;
        graph[u][v] = true;
        graph[v][u] = true;
    }

    Solution obj;
    cout << obj.graphColoring(graph, M, N) << endl;

    return 0;
}