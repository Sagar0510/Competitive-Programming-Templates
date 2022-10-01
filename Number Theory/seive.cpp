vector<int> sieve(int n) {
    vector<int> primes, is_prime(n + 1, 1);
    for (int i = 2; i * i <= n; i++)
        if (is_prime[i])
            for (int j = i + i; j <= n; j += i)
                is_prime[j] = 0;
    for (int i = 2; i <= n; i++)
        if (is_prime[i])
            primes.push_back(i);
    return primes;
}