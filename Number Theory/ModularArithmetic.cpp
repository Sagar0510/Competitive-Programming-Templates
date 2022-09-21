ll qexp(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mod_inv(ll n,ll m){return qexp(n,mod-2,m);} // for prime mod
ll add_mod(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll multiply_mod(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll subtract_mod(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll divide_mod(ll a, ll b, ll m) {a = a % m; b = b % m; return (multiply_mod(a, mod_inv(b, m), m) + m) % m;}  //only for prime m


