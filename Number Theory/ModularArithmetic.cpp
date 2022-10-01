int qexp(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
int mod_inv(int n,int m){return qexp(n,mod-2,m);} // for prime mod
int add_mod(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int multiply_mod(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int subtract_mod(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int divide_mod(int a, int b, int m) {a = a % m; b = b % m; return (multiply_mod(a, mod_inv(b, m), m) + m) % m;}  //only for prime m
