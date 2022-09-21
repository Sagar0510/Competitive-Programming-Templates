ll mod_multiplication(ll a,ll b){ // (x*y)%mod with intermediate states = no overflow
    ll res=0;
    while(b){
        if(b&1) res=(res+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return res;
}
