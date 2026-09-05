class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, 0);

        for (int i = 0; i < n; i++) {

            // Graph có thể không liên thông
            if (color[i] != 0)
                continue;

            queue<int> q;

            color[i] = 1;
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {

                    if (color[v] == 0) {
                        color[v] = 3 - color[u];
                        q.push(v);
                    }

                    else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};