
int powerr(int n, int k){
    if(k == 0){
        return 1;
    }
    int rec = powerr( (n*(int)n)  , k/2);
    if(k%2) return (rec * n ) ;
    else return rec;
}


