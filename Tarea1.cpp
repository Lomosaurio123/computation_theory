#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> generateCombinations(int n) {
    vector< vector< string > > dp(n + 1);
    dp[ 1 ] = {"0", "1"};

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

int main() {
    int n = 5;
    vector< string > combinations = generateCombinations(n);

    for (const string &combination : combinations) {
        cout << combination << " ";
    }

    return 0;
}