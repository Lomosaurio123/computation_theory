#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Función para calcular los primos hasta n usando el algoritmo de eratostenes

vector<int> sieveOfEratosthenes(int n) {

    vector<bool> isPrime(n + 1, true);

    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    vector< int > primes;
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            primes.push_back( p );
        }
    }

    return primes;
}

vector<string> generateCombinations(int n) {
    vector< vector< string > > dp(n + 1);
    dp[ 1 ] = {"1"};

    for (int i = 2; i <= n; ++i) {
        for (const string &prev : dp[i - 1]) {
            dp[i].push_back(prev + "0");
            dp[i].push_back(prev + "1");
        }
    }

    vector<string> combinations;
    for ( const vector< string > &lengthCombinations : dp ) {
        
        combinations.insert( combinations.end(), lengthCombinations.begin(), lengthCombinations.end() );
        
    }

    return combinations;
}


vector< string > generatePrimeCombinations( int n ) {

    long long universe_size = 0;
    int i = 0;

    while (universe_size < n) {
        universe_size += pow(2, i);
        i++;
    }

    vector< int > primes;

    vector< string > universe, primeCombinations;

    primes = sieveOfEratosthenes( n );

    universe = generateCombinations( i );

    for (int prime : primes) primeCombinations.push_back( universe[ prime - 1 ] );


    return primeCombinations;

}


int main() {

    vector< string > result;
    
    result = generatePrimeCombinations(1000000);

    for( auto value : result ) cout << value << endl;

}