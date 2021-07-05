

vector < int > primes;
vector < bool > is_prime;

void sieve(int __N){
    
    is_prime.resize(__N, 0);
    is_prime[0] = 1;
    is_prime[1] = 1;
    
    for(int i=2; i*i<=__N; i++){
        if(is_prime[i] == 0){
            for(int j=i*i; j<=__N; j+=i){
                is_prime[j] = 1;
            }
        }
    }

    for(int i=0; i<__N; ++i){
        if(is_prime[i])continue;
        primes.push_back(i);
    }
}

