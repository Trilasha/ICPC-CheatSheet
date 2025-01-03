//Applicable only for Without Loops and Multiple Edged Graphs - undirected graphs
int n,m;
vector<vector<int>> adj;
vector<bool> visited,vis2;
vector<int> parent,dis;
vector<int> st;
int cycle_start, cycle_end;

bool dfs(int v, int par) { // passing vertex and its parent vertex
    visited[v] = true;
    for (int u : adj[v]) {
        if(u == par) continue; // skipping edge to parent vertex
        if (visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
}

void find_cycle() {
    visited.assign(n, false);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && dfs(v, parent[v]))
            break;
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);

        cout << "Cycle found: ";
        for (int v : cycle)
            st.pb(v);
        cout << endl;
    }
}


//Directed graph 
vector<ll> path,vis;
vector<vector<ll>> adj;
stack<ll> st;
void dfs(ll node){
    if(path.size()!=0) return;
    st.push(node);
    vis[node]=1;
    for(auto &child:adj[node]){
        if(!vis[child]){
            dfs(child);
        }else if(vis[child]==1 && path.size()==0){
            path.pb(child);
            while(st.top()!=child){
                path.pb(st.top());
                st.pop();
            }
            path.pb(child);
            return;
        }
    }
    vis[node]=2;
    st.pop();
}

