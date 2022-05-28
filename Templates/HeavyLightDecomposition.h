struct HLD{
    int cnt;
    vector < int > depth, sz, parent, tp, idx;  
    // initialize tree
    HLD( vector < vector < int > >  &gr , int root){
        int n = gr.size();
        depth.resize(n, -1);
        // init tree
        sz.resize(n, 0);
        parent.resize(n, 0);
        tp.resize(n, 0);
        idx.resize(n, 0);
        dfs_sz(gr, root, root);
        cnt = 0;
        dfs_hld(gr, root, root, root);
    }

    int dfs_sz(vector < vector < int > > &gr, int cur, int par){
        depth[cur] = depth[par]+1;
        sz[cur] = 1;
        parent[cur] = par;
        for(auto x: gr[cur]){
            if(x == par)continue;
            sz[cur]+=dfs_sz(gr, x, cur);
        }
        return sz[cur];
    }

    void dfs_hld(vector < vector < int > > &gr, int cur, int par, int top){
        tp[cur] = top;
        idx[cur] = cnt++;
        int mx_sz = -1, mx_child = -1;
        for(auto x: gr[cur]){
            if(x == par)continue;
            if(sz[x]>mx_sz){
                mx_sz = sz[x];
                mx_child = x;
            }
        }

        if(mx_child == -1)return;
        dfs_hld(gr, mx_child, cur, top);
        for(auto x: gr[cur]){
            if( x == par or x == mx_child )continue;
            dfs_hld(gr, x, cur, x);
        }
    }

    int path(int x, int y){
        int ans;
        while(tp[x]!=tp[y]){
            if(depth[tp[x]]<depth[tp[y]])swap(x, y);
            // operation [idx[tp[x]] .... idx[x]] 
            x = parent[tp[x]];
        }
        if(depth[x]>depth[y]) swap(x, y);
        // opertion [idx[x] ... idx[y]]
        return ans;
    }
};
