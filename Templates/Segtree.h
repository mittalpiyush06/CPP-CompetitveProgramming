class segtree{

public: 

    vector < int > v;
    int size;

    void init(int n){
        size = 1;
        while(size<n) size*=2;
        v.resize(size*2, 0);
    }

    void set(int x, int val){ 
        set(x, val, 0, 0, size);                              
    }

    void set(int x, int val, int cur, int lx, int rx){
        if(rx-lx == 1){
            v[cur] = val;
        }else{
            int mid = (lx+rx)/2;
            if(x<mid){
                set(x, val, 2*cur+1, lx, mid);
            }else{
                set(x, val, 2*cur+2, mid, rx);
            }
            v[cur] = v[2*cur+1]+v[2*cur+2];
        } 
    }

    int get(int l, int r){
        return get(l, r, 0, 0, size);
    }
    
    int get(int l, int r, int cur, int lx, int rx){
        if(l>=rx or r<=lx){
            return (int)0; 
        }
        if(l<=lx and r>=rx){
            return v[cur]; 
        }
        int m = (lx+rx)/2;
        return ( get(l, r, 2*cur+1, lx, m) + get(l, r, 2*cur+2, m, rx) );
    }

};


