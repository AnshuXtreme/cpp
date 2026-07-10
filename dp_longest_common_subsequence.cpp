#include <iostream>
#include <vector>
#include <string>

int lcs(const std::string& a, const std::string& b) {
    int m = a.size(), n = b.size();
    std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);

    // backtrack to find actual LCS
    std::string result;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) { result += a[i-1]; i--; j--; }
        else if (dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    std::reverse(result.begin(), result.end());
    std::cout << "LCS string: " << result << "\n";
    return dp[m][n];
}

int main() {
    std::string a = "ABCBDAB";
    std::string b = "BDCAB";
    std::cout << "LCS length: " << lcs(a, b) << "\n"; // 4 (BCAB)
    return 0;
}
