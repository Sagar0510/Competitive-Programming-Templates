

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*---------------------------------------------------------------------------------------------------------------------------*/
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
int mminvprime(int a, int b) {return expo(a, b - 2, b);}
bool revsort(int a, int b) {return a > b;}
int combination(int n, int r, int m, int *fact, int *ifact) {int val1 = fact[n]; int val2 = ifact[n - r]; int val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
int phin(int n) {int number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (int i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
int getRandomNumber(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);} 
/*--------------------------------------------------------------------------------------------------------------------------*/

struct Hashing{
    string s;
    int n;
    int primes;
    vector<int> hashPrimes = {1000000009, 100000007};
    const int base = 31;
    vector<vector<int>> hashValues;
    vector<vector<int>> powersOfBase;
    Hashing(string a){
        primes = (hashPrimes).size();
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        s = a;
        n = s.length(); 
        for(int i = 0; i < (hashPrimes).size(); i++) {
            powersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for(int j = 1; j <= n; j++){
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
        }
        for(int i = 0; i < (hashPrimes).size(); i++) {
            hashValues[i].resize(n);
            for(int j = 0; j < n; j++){
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    void addCharacter(char ch){
        s += ch;
        n = (s).size();
        for(int i = 0; i < (hashPrimes).size(); i++){
            while((powersOfBase[i]).size() < (s).size()){
                powersOfBase[i].pb((powersOfBase[i].back() * base) % hashPrimes[i]);   
            }
        }
        for(int i = 0; i < (hashPrimes).size(); i++){
            while((hashValues[i]).size() < (s).size()){
                if((hashValues[i]).size() == 0){
                    hashValues[i].pb((s[0] - 'a' + 1LL) % hashPrimes[i]);
                }else{
                    int extraHash = hashValues[i].back() + ((s.back() - 'a' + 1LL) * powersOfBase[i][(s).size() - 1]) % hashPrimes[i];
                    hashValues[i].pb((extraHash + hashPrimes[i]) % hashPrimes[i]);
                }
            }
        }
    }
    vector<int> substringHash(int l, int r){ // extra O(log) factor
        vector<int> hash(primes);
        for(int i = 0; i < primes; i++){
            int val1 = hashValues[i][r];
            int val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            hash[i] = mod_mul(mod_sub(val1, val2, hashPrimes[i]), mminvprime(powersOfBase[i][l], hashPrimes[i]), hashPrimes[i]);
        }
        return hash;
    }
    bool compareSubstrings(int l1, int r1, int l2, int r2){ // use this for comparing strings faster
        if(l1 > l2){
            swap(l1, l2);
            swap(r1, r2);
        }
        for(int i = 0; i < primes; i++){
            int val1 = mod_sub(hashValues[i][r1], (l1 > 0 ? hashValues[i][l1 - 1] : 0LL), hashPrimes[i]);
            int val2 = mod_sub(hashValues[i][r2], (l2 > 0 ? hashValues[i][l2 - 1] : 0LL), hashPrimes[i]);
            if(mod_mul(val1, powersOfBase[i][l2 - l1], hashPrimes[i]) != val2)
                return false;
        }   
        return true;
    }
};

