#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> generateCombinations(int n) {
    std::vector<std::vector<std::string>> dp(n + 1);
    dp[1] = {"0", "1"};

    for (int i = 2; i <= n; ++i) {
        for (const std::string &prev : dp[i - 1]) {
            dp[i].push_back(prev + "0");
            dp[i].push_back(prev + "1");
        }
    }

    std::vector<std::string> combinations;
    for (const std::vector<std::string> &lengthCombinations : dp) {
        combinations.insert(combinations.end(), lengthCombinations.begin(), lengthCombinations.end());
    }

    return combinations;
}

int main() {
    int n = 2;
    std::vector<std::string> combinations = generateCombinations(n);

    for (const std::string &combination : combinations) {
        std::cout << combination << " ";
    }

    return 0;
}