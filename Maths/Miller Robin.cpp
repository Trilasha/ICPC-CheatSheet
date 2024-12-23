bool composite(ll m, ll a, ll d, ll s) {
    ll x = binpow(a, d, m);
    if(x == 1 || x == m-1) return 0;
    for(ll r = 1; r <= s; r++) {
        x = (u128)x * x % m;
        if(x==m-1) return 0;
    }
    return 1;
}
bool miller_rabin(ll x) {
    if(x < 2) return 0;
    if(x==2) return 1;
    if(x % 2 == 0) return 0;
    ll s = 0, d = x-1; 
    while((d & 1)==0) {
        s++;
        d >>= 1;
    }
    for(ll a:{2,3,5,7,11,13,17,19,23,29,31,37}){
        if(x==a) return 1;
        if(composite(x, a, d, s)) return 0;
    }
    return 1;
}
ll f(ll x, ll n) {
    x = binpow(x, 2, n);
    return x++ == n ? 0 : x;
}
ll pollard(ll n) {
    if(n%2==0) return 2;
    for(ll i = 2;; i++) {
        ll x = i, y = f(x, n), d;
        while((d = __gcd(n + y - x, n)) == 1) {
            x = f(x, n), y = f(f(y, n), n);
        }
        if(d != n) return d;
    }
}
void ff(ll x) {
    if(x < 2) return;
    if(miller_rabin(x)) {
        ppf.insert(x);
        return;
    }
    else {
        ll d = pollard(x);
        ff(d);
        ff(x/d);
}}