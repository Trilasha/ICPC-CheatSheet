const ll N = 100005;
vector<ll> f(N),invf(N);

ll power(ll a,ll b)
{
    if(b==0)
        return 1;
    else
    {
        ll x=power(a,b/2);
        ll y=(x*x)%modval;
        if(b%2)
            y=(y*a)%modval;
        return y;
    }
}

ll inverse(ll a)
{
    return power(a,modval-2);
}

void precompute()
{
    f[0]=1;
    for(int i=1;i<N;i++)
        f[i]=(f[i-1]*i)%modval;
    for(int i=0;i<N;i++)
        invf[i]=inverse(f[i]);
}