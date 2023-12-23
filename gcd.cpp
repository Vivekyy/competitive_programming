using namespace std;

#include <bits/stdc++.h>
#define ll long long
#define dqll deque<ll>

ll gcd(ll a, ll b){ return b ? gcd(b, a % b) : a; }

ll lcm(ll a, ll b){ return a*b/gcd(a,b); }

// extended version to find x, y such that ax + by = gcd(a, b)
ll gcd_ext(ll a, ll b, ll &x, ll &y){
    if (b == 0) {x = 1, y = 0; return a;}
    ll x1, y1, d = gcd_ext(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll pos_mod(ll a, ll b) {
    ll ret = a % b;
    return ret>0 ? ret : ret+b; 
}

// a^-1 (mod N)
// ax + Ny = gcd(a,N) = 1 -> ax = 1 (mod N) -> x = a^-1
ll inv(ll a, ll N){ 
    ll x,y = 0;
    ll d = gcd_ext(a,N,x,y);
    return d>1 ? -1 : pos_mod(x, N); 
}

// x^a (mod N)
// If N prime, x^(N-1) = 1 (mod N) -> x^(N-2) = x^(-1) (mod N)
// Common prime moduli: 10^9 + 7, 998244353
ll pow_mod(ll x, ll a, ll N){
    if (a==0)
        return 1;
    ll t = pow_mod(x, a/2, N);
    return a%2==0 ? pos_mod(t*t, N) : pos_mod(t*t*x, N);
}

ll totient(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

dqll totient_1_to_n(int n) {
    dqll phi(n + 1);
    for (ll i = 0; i <= n; i++)
        phi[i] = i;

    for (ll i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (ll j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}