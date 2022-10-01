int exteuclid(int a, int b, int &x, int &y) {
    if (b == 0) {x = 1, y = 0; return a;}
    int x1, y1, d = exteuclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
bool lde(int a, int b, int c, int &x, int &y) {
    int d = exteuclid(abs(a), abs(b), x, y);
    if (c % d) return false; 
    x *= c / d; 
    y *= c / d;
    if (a < 0) x = -x;
    if (b < 0) y = -y;
    return true;
}