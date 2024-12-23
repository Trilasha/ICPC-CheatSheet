void extendgcd(ll a, ll b, ll *v)
{
    if (b == 0)
    {
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return;
    }
    extendgcd(b, a % b, v);
    ll x = v[1];
    v[1] = v[0] - v[1] * (a / b);
    v[0] = x;
    return;
} // pass an arry of size1 3
ll mminv(ll a, ll b)
{
    ll arr[3];
    extendgcd(a, b, arr);
    return arr[0];
} // for non prime b
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }

int phi[LIM];
void calculatePhi() {
	rep(i,0,LIM) phi[i] = i&1 ? i : i/2;
	for (int i = 3; i < LIM; i += 2) if(phi[i] == i)
		for (int j = i; j < LIM; j += i) 
            phi[j] -= phi[j] / i;
}