
vector<int> primeFactors(int n) {
    vector<int> pfs;
    while (n % 2 == 0) {
        pfs.pb(2);
        n = n / 2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            pfs.pb(i);
            n = n / i;
        }
    }
    if (n > 2)
        pfs.pb(n);
    return pfs;
}