#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define MAXN 5000
ll n, t[4*MAXN];

// Call with:
// build(a, 1, 0, n-1);
void build(ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = min(t[v*2], t[v*2+1]); //replace as needed
    }
}

// Call with:
// rangemin(1, l, r, l, r);
ll rangemin(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return min(rangemin(v*2, tl, tm, l, min(r, tm)), rangemin(v*2+1, tm+1, tr, max(l, tm+1), r));
}