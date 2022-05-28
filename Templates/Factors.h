
vector < pair < int, int > > factorisation(int n) {
    vector < pair < int, int > > factors;
    int cnt = 0;
    while (n % 2 == 0) {
        n /= 2;
        cnt++;
    }
    if (cnt) factors.push_back({2, cnt});
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            cnt = 0;
            while (n % i == 0) {
                n/=i;
                cnt++;
            }
            factors.push_back({i, cnt});
        }
    }
    if (n > 1) {
        factors.push_back({n, 1});
    }
    return factors;
}

