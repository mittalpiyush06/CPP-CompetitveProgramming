
struct lzy_segtree{

    vector < int > v, lzy;
    int size;

    lzy_segtree(int n){
        size = 1;
        while(size<n) size*=2;
        v.resize(size*2, INT_MAX);
        lzy.resize(size*2, INT_MAX);
    }

    void propogate(int cur, int lx, int rx){
        v[cur] = min(v[cur], lzy[cur]); 
        if(rx-lx==1){
            lzy[cur] = INT_MAX;
            return;
        }
        if(lzy[cur]==INT_MAX)return;
        lzy[2*cur+1] = min(lzy[2*cur+1], lzy[cur]);
        lzy[2*cur+2] = min(lzy[2*cur+2], lzy[cur]);
        lzy[cur] = INT_MAX;
    }
    
    void set_lz(int l, int r, int val){
        set_lz(l, r, val, 0, 0, size);
    }
    
    void set_lz(int l, int r, int val, int cur, int lx, int rx){
        propogate(cur, lx, rx);
        if( l>=rx or r<=lx ){
            return;
        }
        if( l<=lx and r>=rx ){
            lzy[cur] = min(lzy[cur], val);
            propogate(cur, lx, rx);
            return;
        }
        int m = (lx+rx)/2;
        set_lz(l, r, val, 2*cur+1,  lx, m);
        set_lz(l, r, val, 2*cur+2, m, rx);
        v[cur] = min(v[2*cur+1], v[2*cur+2]);
    }
    
    int get_lz(int l, int r){
        return get_lz(l, r, 0, 0, size);
    }

    int get_lz(int l, int r, int cur, int lx, int rx){
        propogate(cur, lx, rx);
        if(l>=rx or r<=lx){
            return (int)INT_MAX;
        }
        if(l<=lx and r>=rx){
            return v[cur];
        }
        int m = (lx+rx)/2;
        return min( get_lz(l, r, 2*cur+1, lx, m) , get_lz(l, r, 2*cur+2, m, rx) );
    }
    
};


