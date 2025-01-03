struct LCA{
    vector<vector<int>> up;
    vector<int> tin, tout, distance;
    int timer;
    vector<vector<int>>store;
    LCA(int n) {
        timer = 0;
        tin.resize(n);
        tout.resize(n);
        up.assign(n, vector<int>(21, -1));
        distance.assign(n, 0);
        store.assign(n,{});
    }
    void dfs(int v, int p, vector<vector<int>> &adj, int dis,vector<int>count) {
        distance[v]=dis;
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i < 21; i++)
            up[v][i] = up[up[v][i - 1]][i - 1];
 
        for(int i=0;i<30;i++){
          if(cost[v]&(1<<i)) count[i]++;
        }
        store[v]=count;
        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v, adj, dis+1,count);
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int lca(int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = 20; i >= 0; i--) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
    int dist(int u, int v) {
        int w = lca(u, v);
        return abs(distance[u] + distance[v] - 2*distance[w]);
    }
};