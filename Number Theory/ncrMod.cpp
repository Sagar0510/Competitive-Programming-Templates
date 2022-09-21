ll qexp(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mod_inv(ll n,ll m){return qexp(n,mod-2,m);} // for prime mod
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mod_inv(b, m), m) + m) % m;}  //only for prime m

vll fact;
void computeFact(ll n){
    fact.resize(n+1);
    fact[0]=1;
    rep(i,1,n+1) fact[i]=mod_mul(fact[i-1],i,mod);
}
ll ncr(ll n,ll r,ll mod){
    if(n<r) return 0;
    if(r==0) return 1;
    return (((fact[n]*mod_inv(fact[r],mod))%mod)*(mod_inv(fact[n-r],mod)))%mod;
}

