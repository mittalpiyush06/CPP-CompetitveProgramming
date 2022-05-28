int powerr(int n, int k, bool _take, int _mod = 1e9+7){
    int ans = 1;
    if(_take){
        n %= _mod;
    }
    while(k > 0){
        if( (k&1ll) ){
            ans *= n;
            if(_take)
                ans %= _mod;
        }
        n *= n;
        if(_take)
            n %= _mod;
        k = k >> 1ll;
    }
    return ans;
}
