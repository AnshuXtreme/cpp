#include <iostream>
#include <vector>

int knapsack(int W, const std::vector<int>& wt, const std::vector<int>& val, int n) {
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(W+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i-1][w];
            if (wt[i-1] <= w)
                dp[i][w] = std::max(dp[i][w], dp[i-1][w-wt[i-1]] + val[i-1]);
        }
    }
    return dp[n][W];
}

int main() {
    std::vector<int> val = {60, 100, 120};
    std::vector<int> wt  = {10,  20,  30};
    int W = 50, n = val.size();

    std::cout << "Max value: " << knapsack(W, wt, val, n) << "\n"; // 220
    return 0;
}
