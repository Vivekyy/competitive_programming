#define ll long long

int gcd(int a, int b){ return b ? gcd(b, a % b) : a; }

// extended version to find x, y such that ax + by = gcd(a, b)
ll gcd_ext(ll a, ll b, ll &x, ll &y){
    if (b == 0) {x = 1, y = 0; return a;}
    ll x1, y1, d = gcd_ext(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll pmod(ll a, ll b) { ll ret = a % b; return ret>0 ? ret : ret+b; }

// using above two equations:
// a^-1 (mod N): ax + Ny = gcd(a,N) = 1 -> ax = 1 (mod N) -> x = a^-1
ll inv(ll a, ll N){ ll x,y = 0; ll d = gcd_ext(a,N,x,y); return d>1 ? -1 : pmod(x, N); } 