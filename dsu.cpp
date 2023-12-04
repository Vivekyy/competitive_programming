using namespace std;
#define ll long long
#define dqll deque<ll>

class DSU{
public:
    dqll parent;
    dqll size;
    ll num_sets;
    DSU(ll n){
        parent.resize(n);
        size.resize(n);
        num_sets = n;
    }

    // Assignment flattens tree during lookup
    ll find_set(ll a){
        if (a == parent[a])
            return a;
        return parent[a] = find_set(parent[a]);
    }

    // Want to maximize size to make wider trees for quicker lookup
    void union_sets(ll a, ll b){
        a = find_set(a);
        b = find_set(b);
        if (a != b){
            if (size[a] < size[b])
                swap(a,b);
            parent[b] = a;
            size[a] += size[b];
            num_sets--;
        }
    }
};