using namespace std;

#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define dqll deque<ll>

#define llmax LLONG_MAX
#define llmin LLONG_MIN

deque<deque<pll>> adj;

void dijkstra(ll s, dqll &d, dqll &p) {
    ll n = adj.size();
    d.assign(n, llmax);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (ll i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == llmax)
            break;

        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}