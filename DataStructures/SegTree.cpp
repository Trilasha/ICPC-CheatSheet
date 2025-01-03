struct segtree{
	vector<ll> v;ll id=0,sz;//id for initialization
	segtree(ll _n){sz=1;while(sz<_n){sz<<=1;}v.assign(2*sz,id);}
	ll func(ll x,ll y){ return x+y;}
	void pull(ll x){ v[x]=func(v[2*x+1],v[2*x+2]);}
	void update(ll i, ll val, ll x, ll lx, ll rx){ // 0-based indexing 
		if(rx-lx==1){ v[x]=val; return;}
		ll m=(lx+rx)/2;
		if(i<m){update(i,val,2*x+1,lx,m);}
		else{update(i,val,2*x+2,m,rx);}
		pull(x);
	}
	void update(ll i, ll val){ update(i,val,0,0,sz);}
	ll query(ll l,ll r,ll x,ll lx,ll rx){ // [l,r) l->INCLUSIVE/ r->EXCLUSIVE
		if(lx>=r || l>=rx) return id;
		if(lx>=l && rx<=r) return v[x];
		ll m=(lx+rx)/2;
		ll s1=query(l,r,2*x+1,lx,m);
		ll s2=query(l,r,2*x+2,m,rx);
		return func(s1,s2);
	}
	ll query(ll l,ll r){ return query(l,r,0,0,sz);}
};