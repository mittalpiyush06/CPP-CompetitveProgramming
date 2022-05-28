
struct dsu{
    vector < int > parent;

    dsu(int _n){
        parent.resize(_n+1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find_set(int v){

        if(v == parent[v]){
            return v;
        }else{
            int result = find_set(parent[v]);
            parent[v] = result;
            return result;
        }

    }

    bool union_sets(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if (a != b){
            parent[b] = a;
            return true;
        }else{
            return false;
        }
    }
};

