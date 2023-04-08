/* computes x such that x ≡ a (mod m), x ≡ b (mod n). If
|a| < m and |b| < n, x will obey 0 ≤ x < lcm(m, n).
Assumes mn < 2^62*/

ll crt(ll a, ll m, ll b, ll n) {
if (n > m) swap(a, b), swap(m, n);
ll x, y, g = euclid(m, n, x, y);
assert((a - b) % g == 0); // e lse no so lution
x = (b - a) % n * x % n / g * m + a;
return x < 0 ? x + m*n/g : x;
