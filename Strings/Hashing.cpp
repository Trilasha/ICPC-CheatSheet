//simple
vector<ll> hash1,power1(2e6+10,1);
vector<ll> invMod1(2e6+10,1);
 
ll radix=31;
ll mod=1e9+7;
 
ll expo(ll b,ll e,ll md){
    ll ans=1;
    while(e){
        if(e&1) ans=(ans*b)%md;
        b=(b*b)%md;
        e/=2;
    }
    return ans;
}
void precal(string &s){
    int n=s.size();
    hash1.resize(n+5);
    ll a=1;
    for(int x=0;x<n;++x){
        hash1[x+1]=(hash1[x]+(s[x]-'a'+1)*a)%mod;
        a=(a*radix)%mod;
    }
}
 
ll invmod(ll p){
    return expo(p,mod-2,mod);
}
void preInv(){
    for(int i=1;i<=1e6+1;i++){
        power1[i]=(power1[i-1]*radix)%mod;
        invMod1[i]=invmod(power1[i]);
    }
}
 
ll calc(ll left,ll right){
    ll val=(hash1[right]-hash1[left-1]+mod)%mod;
    ll ans=(val*invMod1[left-1])%mod;
    return ans;
}




//double-hashing
ll radix=31;
ll mod=1e9+7;
 
vector<ll> hash1,bhash,power1(5e6+30,1);
void precal(string &s){
    int n=s.size();
    hash1.resize(n+5);
    ll a=1;
    for(int x=0;x<n;++x){
        hash1[x+1]=(hash1[x]+(s[x])*a)%mod;
        a=(a*radix)%mod;
    }
}
void preInv(){
    for(int i=1;i<=5e6+10;i++){
        power1[i]=(power1[i-1]*radix)%mod;
        // invMod1[i]=invmod(power1[i]);
    }
}
void back_precal(string &s){
    int n=s.size();
    bhash.resize(n+3);
    ll a=1;
    for(int x=n;x>=1;--x){
        bhash[x]=(bhash[x+1]+(s[x-1])*a)%mod;
        a=(a*radix)%mod;
    }
}
ll back_calc(ll left,ll right){
    ll val=(bhash[left]-bhash[right+1]+mod)%mod;
    // ll ans=(val*invMod1[bhash.size()-right-1])%mod;
    return val;
}
 
// 1 2 3 4 5
// 1 2 3 4 5 6
void solve(){
    string s;
    cin>>s;
    ll n=s.size();
    preInv();
    precal(s);
    back_precal(s);
    ll ans=1;
    vector<ll> mp(n+3);
    mp[1]=1;
    for(ll i=1;i<n;++i){
        ll ind=i+1;
        ll half=ind/2;
        ll left=(hash1[half]*power1[n-ind])%mod;
        if(ind%2)half++;
        ll right=back_calc(half+1,ind);
        //cout<<left<<" "<<right<<endl;
        if(left==right){
            if(ind%2)half--;
            mp[ind]=mp[half]+1;
        }
        ans+=mp[ind];
    }
    // cout<<ans<<endl;
    cout<<ans<<endl;
}