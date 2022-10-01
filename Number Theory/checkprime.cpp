bool prime(int a) {
    if (a <= 1) return 0;
    if (a == 2 || a == 3) return 1;
    if (a % 2 == 0 || a % 3 == 0) return 0;
    for (int i = 5; i <= sqrt(a); i += 6)
        if (a % i == 0 || a % (i + 2) == 0)return 0;
    return 1;
}