#include <bits/stdc++.h>
#define ll long long

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

ll primeFacs(ll n){
    ll cnt=0,sum=1;
    for(int i=0; prime[i]*prime[i]<=n && i<nprime;i++){
        cnt=0;
        while(n%prime[i]==0)
            cnt++;n/=prime[i];
        sum*=(cnt+1);
    }
    if(n>1)
        sum*=2;
    return sum;
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