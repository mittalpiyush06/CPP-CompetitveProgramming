
// link to linear_sieve : https://codeforces.com/blog/entry/54090
// Function included : linear_sieve(N) : (is_composite, primes)
//                     prime_factor(N) : (spf, primes)
//                     euler(N) : (is_composite, primes, phi)
//                     mobius(N) : (is_composte, primes, mobi)
struct sieve{
    vector < int > primes;
    vector < bool > is_composite;
    vector < int > spf;
    vector < int > phi;
    vector < int > mobi;
    void linear_sieve(int N){
        ++N;
        is_composite.resize(N, 0);

        for(int i=2; i<N; ++i){
            if(!is_composite[i]){
                primes.push_back(i);
            }
            for(int j=0; j<(int)primes.size() and i * primes[j] < N; ++j){
                is_composite[i * primes[j]] = 1;
                if(i%primes[j] == (int)0){
                    break;
                }
            }
        }
    }

    void prime_factor(int N){
        ++N;
        spf.resize(N, (int)0);
        iota(spf.begin(), spf.end(), (int)0);

        for(int i=2; i<N; ++i){
            if(spf[i] == i){
                primes.push_back(i);
            }
            for(int j=0; j<(int)primes.size() and i * primes[j] < N; ++j){
                spf[i*primes[j]] = primes[j];
                if( i%primes[j] == (int)0 ){
                    break;
                }
            }
        }
    }
    
    void euler(int N){
        ++N;
        is_composite.resize(N, 0);
        phi.resize(N);
        phi[1] = 1;
        for(int i=2; i<N; ++i){
            if(!is_composite[i]){
                phi[i] = i-1;
                primes.push_back(i);
            }
            for(int j=0; j<(int)primes.size() and i * primes[j] < N; ++j){
                is_composite[i*primes[j]] = 1;
                if(i%primes[j] == (int)0){
                    phi[i*primes[j]] = phi[i] * primes[j];
                }else{
                    phi[i*primes[j]] = phi[i] * phi[primes[j]];
                }
            }
        }
    }

    void mobius(int N){
        ++N;
        is_composite.resize(N, 0);
        mobi.resize(N);
        mobi[1] = 1;
        for(int i=2; i<N; ++i){
            if(!is_composite[i]){
                primes.push_back(i);
                mobi[i] = -1;
            }
            for(int j=0; j<(int)primes.size() and i * primes[j] < N; ++j){
                is_composite[i*primes[j]] = 1;
                if(i%primes[j] == (int)0){
                    mobi[i*primes[j]] = 0;
                }else{
                    mobi[i*primes[j]] = mobi[i] * mobi[primes[j]];
                }
            }
        }

    }

};

