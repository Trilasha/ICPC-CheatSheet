// prints all the prime numbers of a number 
void printprimefactors(ll n){
    if(n<=1) return;
    while(n%2==0){
        cout<<2;
        n=n/2;
    }
    while(n%3==0){
        cout<<3;
        n=n/3;
    }
    for (ll i = 5; i*i<=n; i=i+6){
        while (n%i==0){
            cout<<i;
            n=n/i;
        }
        while(n%(i+2)==0){
            cout<<i+2;
            n=n/(i+2);
        }
    }
    if(n>3) cout<<n;
    return;
    //i/p-->450
    //o/p-->23355
}
//tc-theta(sqrt(n))


// checks if a number is prime or not
bool isPrime(ll n){
    if(n==1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(ll i=5;i*i<=n;i=i+6)
    if(n%i==0 || n%(i+2)==0)
    return false;
    return true;
}

// finds the shortest prime factor for all numbers 
const ll MAXN = 1e6+5;
vector<ll> spf(MAXN,1);

void sieve() {
    spf[0] = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) {
            for (int j = i; j <= MAXN; j += i) {
                if (spf[j] == 1)
                    spf[j] = i;
            }
        }
        // cout<<spf[i]<<" ";
    }
}


// stores all the prime numbers till n
vector<ll> sv(ll n){
    int *arr = new int[n+1]();
    vector<ll> vect;
    for(int i = 2 ; i<= n ; i ++){
        if(arr[i] == 0){
            vect.push_back(i);
            for(int j = 2*i ; j <= n ; j += i){
                arr[j] = 1;
            }
        }
    }
    return vect;
}

void divisors(ll n){
    for (ll i = 1; i*i <=n; i++){
        if(n%i==0){
            cout<<i<<" ";
            if(i!=n/i)
            cout<<n/i<<" ";
        }
    }
}

