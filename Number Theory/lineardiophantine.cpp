ll exteuclid(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {x = 1, y = 0; return a;}
    ll x1, y1, d = exteuclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
bool lde(ll a, ll b, ll c, ll &x, ll &y) {
    ll d = exteuclid(abs(a), abs(b), x, y);
    if (c % d) return false; 
    x *= c / d; 
    y *= c / d;
    if (a < 0) x = -x;
    if (b < 0) y = -y;
    return true;
}
