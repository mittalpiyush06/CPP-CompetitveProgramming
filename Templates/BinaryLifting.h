
struct BinaryLifting{
    vector < vector < int > > gr;
    vector < vector < int > > up;
    vector < int > depth;
    int n, p = 23;
    BinaryLifting(vector < vector < int > > _gr, int _n, int root = 0){
        gr = _gr;
        n = _n;
        up.resize(n);
        for(int i=0; i<n; ++i)up[i].assign(p, -1);
        depth.assign(n, 0);
        dfs(root, root);
    }
    void dfs(int cur, int par){
        if(cur!=par){
            depth[cur] = depth[par]+1;
            up[cur][0] = par;
            for(int i=1; i<p; ++i){
                if(up[cur][i-1]==-1)break;
                up[cur][i] = up[up[cur][i-1]][i-1];
            }
        }
        for(auto x: gr[cur]){
            if(x == par)continue;
            dfs(x, cur);
        }
    }
    int go_up(int cur, int k){
        for(int i=p-1; i>=0; --i){
            if(cur == -1)return -1;
            if((1ll<<i)<=k){
                k-=(1ll<<i);
                cur = up[cur][i];
            }
        }
        return cur;
    }
    int lca(int a, int b){
        if(depth[a]>depth[b]){
            int dif = depth[a]-depth[b];
            a = go_up(a, dif);
        }else{
            int dif = depth[b]-depth[a];
            b = go_up(b, dif);
        }
        for(int i=p-1; i>=0; --i){
            if(up[a][i]!=up[b][i]){
                a = up[a][i];
                b = up[b][i];
            }
        }
        if(a!=b){
            return up[a][0];
        }else{
            return a;
        }
    }
};


