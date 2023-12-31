using namespace std;

#include <bits/stdc++.h>
#define ll long long
#define dqll deque<ll>
#define mpll map<ll, ll>
#define sll set<ll, ll>

const int N=1e7+10;
int prime[20000010]; 
bool isprime[N];
int nprime; 
void sieve(ll a){
    nprime = 0;
    memset(isprime, true, sizeof(isprime));
    isprime[1]=false;
    for(int i=2;i<N;i++){
        if(isprime[i]){
            prime[nprime++]=i;
            for(int j=2;i*j<N;j++)
                isprime[i*j]=false;
        }
    }
}

ll gcd(ll a, ll b){ return b ? gcd(b, a % b) : a; }

ll lcm(ll a, ll b){ return a*b/gcd(a,b); }

// Factoring with sieveFacs:
// sll facs;
// while(tmp > 1){
//     facs.insert(sv[tmp]);
//     tmp /= sv[tmp];
// }
dqll sieveFacs(ll maxVal){
    dqll pfacs;
    dqll out(maxVal);
    for(ll i=0; i<maxVal; i++){
        out[i] = i;
    }

    for(ll i=2; i<maxVal; i++){
        if (out[i] != i)
            continue;
        
        ll x = i;
        while(x < maxVal){
            out[x] = min(out[x], i);
            x += i;
        }
    }

    return out;
}


// ll primeFacs(ll n){
//     ll cnt=0,sum=1;
//     for(int i=0; prime[i]*prime[i]<=n && i<nprime;i++){
//         cnt=0;
//         while(n%prime[i]==0)
//             cnt++;n/=prime[i];
//         sum*=(cnt+1);
//     }
//     if(n>1)
//         sum*=2;
//     return sum;
// } 

mpll primeFacs(ll n){
    mpll out;
    for(int i=2; i*i<=n; i++){
        while(n%i==0){
            n/=i;
            out[i]++;
        }
    }
    return out;
}

sll distinctPrimeFacs(ll n){
    sll out;
    for(int i=2; i*i<=n; i++){
        while(n%i==0){
            n/=i;
            out.insert(i);
        }
    }
    return out;
}

ll numPrimeFacs(ll n){
    ll cnt;
    for(int i=2; i*i<=n; i++){
        while(n%i==0){
            n/=i;
            cnt++;
        }
    }
    return cnt;
}

// bool miller_rabin(ll p, int itt) {
//     if(p<2) 
//         return 0;
//     if(p==2) 
//         return 1;
//     if(p%2==0)
//         return 0;
    
//     unsigned ll s = p-1;
//     while(s%2==0) s/=2;
//     for(ll i=1;i<=itt;i++) {
//         unsigned ll a = rand() % (p-1)+1 , temp = s;
//         unsigned ll mod = modulo(a,temp,(unsigned ll)p);
//         while(mod!=1 && mod!=p-1 && temp!=p-1){
//             mod = Mulmod(mod,mod,(unsigned ll)p);
//             temp*=2;
//         }
//         if(temp%2==0 and mod!=p-1) 
//             return false ;
//     }
//     return true;
// } 