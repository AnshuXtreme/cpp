#include <iostream>
#include <vector>
#include <climits>

// Minimum path sum in grid
int minPathSum(const std::vector<std::vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    dp[0][0] = grid[0][0];
    for (int i=1; i<m; i++) dp[i][0] = dp[i-1][0] + grid[i][0];
    for (int j=1; j<n; j++) dp[0][j] = dp[0][j-1] + grid[0][j];
    for (int i=1; i<m; i++)
        for (int j=1; j<n; j++)
            dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
    return dp[m-1][n-1];
}

// Matrix chain multiplication
int matrixChain(const std::vector<int>& dims) {
    int n = dims.size() - 1;
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    for (int len=2; len<=n; len++) {
        for (int i=0; i<=n-len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k=i; k<j; k++) {
                int cost = dp[i][k] + dp[k+1][j]
                         + dims[i]*dims[k+1]*dims[j+1];
                dp[i][j] = std::min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    std::vector<std::vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    std::cout << "Min path sum: " << minPathSum(grid) << "\n"; // 7

    std::vector<int> dims = {10, 30, 5, 60};
    std::cout << "Matrix chain: " << matrixChain(dims) << "\n"; // 4500
    return 0;
}
