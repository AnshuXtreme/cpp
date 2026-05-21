#include <iostream>
#include <vector>

long long fib(int n) {
    if (n <= 1) return n;
    std::vector<long long> dp(n+1);
    dp[0]=0; dp[1]=1;
    for (int i=2; i<=n; i++) dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

int main() {
    for (int i=0; i<=10; i++)
        std::cout << "fib(" << i << ") = " << fib(i) << "\n";
    return 0;
}
