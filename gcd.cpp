#define ll long long

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

// a^-1 (mod N): ax + Ny = gcd(a,N) = 1 -> ax = 1 (mod N) -> x = a^-1
// extended version to find x, y such that ax + by = gcd(a, b)
ll gcd(ll a, ll b, ll &x, ll &y){
    if (b == 0) {x = 1, y = 0; return a;}
    ll x1, y1, d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// may need to check 0 <= x < N for above equation
ll mod(ll a, ll b){
    ll ret = a % b;
    if (ret < 0)
        ret += b;
    return ret;
}