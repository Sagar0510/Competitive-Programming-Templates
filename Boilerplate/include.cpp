//SAGAR SINGH
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll                   long long 
#define ld                   long double 
#define abs(a,b)             (ll) abs(a-b)
#define rep(i,a,b)           for(ll i=a;i<b;i++) 
#define repr(i,a,b)          for(ll i=a;i>=b;i--)
#define vll                  vector<long long>
#define vvll                 vector<vector<long long> >
#define vpl                  vector<pair<ll,ll> >
#define pll                  pair<ll,ll> 
#define sll                  set<long long>
#define msll                 multiset<long long>
#define mll                  map<ll,ll>
#define all(x)               x.begin(),x.end()
#define rall(x)              x.rbegin(),x.rend()
#define in(v)                for(auto &x:v) cin>>x;
#define out(v)               for(auto &x:v) {cout<<x<<" ";} cout<<'\n';
#define str                  string
#define pb                   push_back
#define ins                  insert
#define lb                   lower_bound
#define ub                   upper_bound
#define ff                   first
#define ss                   second
#define setbits(a)           ( __builtin_popcountll(a))

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif


const ll mod = 1e9+7;
const ll N = 3e5+1;
const ll INF = 1e18;


void solve(){



}

int main(){
    ios_base::sync_with_stdio;
    cin.tie(NULL);cout.tie(0);
    ll t=1;
    cin>>t;
    while(t--) 
        solve();

    return 0;
}
