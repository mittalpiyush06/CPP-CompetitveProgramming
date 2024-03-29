const int Mod = 1e9+7;

template <int mod>
struct ModInt {
    int x;
    ModInt() : x(0) {}
    ModInt(long long x_) {
        if ((x = x_ % mod + mod) >= mod) x -= mod;
    }
    ModInt& operator+=(ModInt rhs) {
        if ((x += rhs.x) >= mod) x -= mod;
        return *this;
    }
    ModInt& operator-=(ModInt rhs) {
        if ((x -= rhs.x) < 0) x += mod;
        return *this;
    }
    ModInt& operator*=(ModInt rhs) {
        x = (unsigned long long)x * rhs.x % mod;
        return *this;
    }
    ModInt& operator/=(ModInt rhs) {
        x = (unsigned long long)x * rhs.inv().x % mod;
        return *this;
    }
    int _powerr(int n, int k){
        if(k == 0){
            return 1;
        }
        int rec = _powerr( (n*(long long)n)%mod , k/2)%mod;
        if(k%2) return ( rec*(long long)n ) % mod;
        else return rec;
    }

    ModInt operator-() const { return -x < 0 ? mod - x : -x; }
    ModInt operator+(ModInt rhs) const { return ModInt(*this) += rhs; }
    ModInt operator-(ModInt rhs) const { return ModInt(*this) -= rhs; }
    ModInt operator*(ModInt rhs) const { return ModInt(*this) *= rhs; }
    ModInt operator/(ModInt rhs) const { return ModInt(*this) /= rhs; }
    bool operator==(ModInt rhs) const { return x == rhs.x; }
    bool operator!=(ModInt rhs) const { return x != rhs.x; }
    ModInt inv() const { return _powerr(x, mod - 2); }
    
    friend ostream& operator<<(ostream& s, ModInt<mod> a){ s << a.x; return s; }
    friend istream& operator>>(istream& s, ModInt<mod>& a){ s >> a.x; return s; }
};

using mint = ModInt<Mod>;



