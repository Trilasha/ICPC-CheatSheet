//diameter of a tree
void dfs(ll node,ll par){
    for(auto &child:adj[node]){
        if(child==par)continue;
        depth[child]=depth[node]+1;
        dfs(child,node);
    }
}
void solve(){
    ll n;
    cin>>n;
    fr(i,n-1){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
   }
   ll max_depth=0;
   dfs(1,-1);
   ll ind=-1;
   for(ll i=1;i<=n;++i){
        if(depth[i]>max_depth){
            max_depth=depth[i];
            ind=i;
        }
        depth[i]=0;
   }
   max_depth=0; 
   dfs(ind,-1);
   for(ll i=1;i<=n;++i){
       max_depth=max(max_depth,depth[i]);
   }
   cout<<max_depth<<endl;
 
}


// approach in-out dp on trees
ll dfs1(ll node,ll par){
    ll dis=0;
    sib_cnt[node]=1;
    for(auto child: adj[node]){
        if(child!=par){
            dfs1(child,node);
            sib_cnt[node]+=sib_cnt[child];
            dis+=in[child]+sib_cnt[child];
        }
    }
    in[node]=dis;
    return dis;
}
 
void dfs2(ll node,ll par){
    ll val=0;
    for(auto child: adj[node]){
        if(child!=par){
            val+=in[child]+sib_cnt[child]*2;
        }
    }
    for(auto &child:adj[node]){
        if(child!=par){
            out[child]=out[node]+(n-sib_cnt[node]+1)+val-in[child]-sib_cnt[child]*2;
            dfs2(child,node);
        }
    }
}



//BINARY-LIFTING
ll LOG;
vector<ll> depth;
vector<vector<ll>> up;
void precal(ll n,vector<ll> &parent){
    LOG=0;
    while((1<<LOG)<=n){
        LOG++;
    }
    up.resize(n+1,vector<ll>(LOG+1));
    depth.resize(n+1);
    for(ll i=1;i<LOG;++i){
        for(ll j=0;j<n;++j){
            up[j][0]=parent[j];
            if(j!=0){
                depth[j]=depth[parent[j]]+1;
            }
            up[j][i]=up[up[j][i-1]][i-1];
        }
    }
 
}
void solve(){
    ll n,q;
    cin>>n>>q;
    vector<ll> parent(n+1);
    for(ll i=1;i<n;++i){
        ll x;
        cin>>x;
        x--;
        parent[i]=x;
    }
    //printv(parent);
    precal(n,parent);
 
    for(ll i=0;i<q;++i){
        // line
        ll node,k;
        cin>>node>>k;
        node--;
        ll ans;
        if(depth[node]<k){
            cout<<-1<<endl;
        }else{
            for(ll i=0;i<LOG;++i){
                if(k&(1<<i)){
                    node=up[node][i];
                }
            }
            cout<<node+1<<endl;
        }
    }
}


//Euler Tour Technique -> to flatten the tree into an array 
//Binary Indexed Tree (Fenwick Tree)  -> to perform the update and query operations on the flattened tree
vector<ll> start(200005),endd(200005);
vector<ll> val;ll timer = 1;
 
class BIT{
    vector<ll> bit;
public:
    BIT(ll n){
        bit.resize(n+1,0);
    }
    void update(ll x, ll val,ll n){
        for(; x <= n; x += x&-x)
            bit[x] += val;
    }
    ll query(ll x){
        ll sum = 0;
        for(; x > 0; x -= x&-x)
            sum += bit[x];
        return sum;
    }
};
 
void euler(ll node,ll par=-1){
    start[node]=timer++;
    for(auto child:adj[node]){
        if(child!=par){
            euler(child,node);
        }
    }
    endd[node]=timer-1;
}
