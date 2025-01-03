vector<ll> dijkstra(vector<vector<pair<int,int>>> &adj,int n,int S){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dis(n + 1, 1e18);
    vector<ll> parent(n + 1);
    for (ll i = 1; i <= n; ++i)
        parent[i] = i;

    dis[S] = 0;
    pq.push({0, S});

    while (!pq.empty()){
        ll distance = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        //trying to add the set erase functionality somehow (though tc remains the same for both pq and set)
        if(distance>dis[node]) continue;

        for (auto &i : adj[node]){
            ll childNode = i.first;
            ll edgeWeight = i.second;
            if (distance + edgeWeight < dis[childNode]){
                dis[childNode] = distance + edgeWeight;
                pq.push({dis[childNode], childNode});
                parent[childNode] = node;
            }
        }
    }
    /*
     if (dis[n] == 1e18)
        return {-1};
        vector<ll> ans;
        ll tNode = n;
        ans.push_back(tNode);
        while (parent[tNode] != tNode){
            ans.push_back(parent[tNode]);
            tNode = parent[tNode];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    */
  return dis;
}