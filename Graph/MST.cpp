void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<pll>> adj(n+1);
    fr(i,m){
        ll x,y,wt;
        cin>>x>>y>>wt;
        adj[x].pb({y,wt});
        adj[y].pb({x,wt});
    }
    priority_queue<pair<ll,pll>,vector<pair<ll,pll>>,greater<pair<ll,pll>>> pq;
    pq.push({0,{1,0}});
    ll ans=0;
    vector<ll> vis(n+1);
    while(!pq.empty()){
        ll wt=pq.top().ff;
        ll node=pq.top().ss.ff;
        ll par=pq.top().ss.ss;
        pq.pop();
        if(vis[node]) continue;
        ans+=wt;
        vis[node]=1;
        for(auto &i: adj[node]){
            if(!vis[i.ff]){
                pq.push({i.ss,{i.ff,node}});
            }
        }
    }
    for(ll i=1;i<=n;++i){
        if(!vis[i]){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
    }
    cout<<ans<<endl;
}