vector<vector<ll>> adj,adjRev;
vector<ll> vis,order,ans;
void dfs(ll node,ll pass,ll component){
    vis[node]=1;
    vector<ll> newAdj=((!pass)?adj[node]:adjRev[node]);
    for(auto &i:newAdj){
        if(!vis[i]) dfs(i,pass,component);
    }
    if(!pass)order.pb(node);
    ans[node]=component;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    adj.resize(n+1);
    adjRev.resize(n+1);
    vis.resize(n+1);
    ans.resize(n+1);
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adjRev[v].pb(u);
    }
    for(ll i=1;i<=n;++i){
        if(!vis[i]){
            dfs(i,0,0);
        }
    }
    reverse(all(order));
    vis.assign(n+1,0);
    ll components=1;
    for(auto &node:order){
        if(!vis[node]){
            dfs(node,2,components);
            components++;
        }
    }
    cout<<components-1<<endl;
    for(ll i=1;i<=n;++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
 
}
