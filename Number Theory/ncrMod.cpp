int qexp(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
int mod_inv(int n,int m){return qexp(n,mod-2,m);} // for prime mod
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mod_inv(b, m), m) + m) % m;}  //only for prime m

vector<int> fact;
void computeFact(int n){
    fact.resize(n+1);
    fact[0]=1;
    rep(i,1,n+1) fact[i]=mod_mul(fact[i-1],i,mod);
}
int ncr(int n,int r,int mod){
    if(n<r) return 0;
    if(r==0) return 1;
    return (((fact[n]*mod_inv(fact[r],mod))%mod)*(mod_inv(fact[n-r],mod)))%mod;
}
