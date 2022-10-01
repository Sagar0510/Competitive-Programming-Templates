
int qexp(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a  % mod;
        a = a * a  % mod;
        b >>= 1;
    }
    return res;
}

int stringToInt(str s){
    int res=0,n=s.size();
    repr(i,n-1,0) res+=(s[i]-'0')*qexp(10,n-i-1);
    return res;
}
