#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

// Max sum subarray of size k
int maxSumSubarray(const std::vector<int>& arr, int k) {
    int sum = 0, maxSum = 0;
    for (int i = 0; i < k; i++) sum += arr[i];
    maxSum = sum;
    for (int i = k; i < (int)arr.size(); i++) {
        sum += arr[i] - arr[i-k];
        maxSum = std::max(maxSum, sum);
    }
    return maxSum;
}

// Longest substring without repeating characters
int longestUniqueSubstr(const std::string& s) {
    std::unordered_map<char, int> map;
    int left = 0, maxLen = 0;
    for (int right = 0; right < (int)s.size(); right++) {
        if (map.count(s[right]))
            left = std::max(left, map[s[right]] + 1);
        map[s[right]] = right;
        maxLen = std::max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    std::vector<int> arr = {2, 1, 5, 1, 3, 2};
    std::cout << "Max sum (k=3): " << maxSumSubarray(arr, 3) << "\n"; // 9

    std::string s = "abcabcbb";
    std::cout << "Longest unique: " << longestUniqueSubstr(s) << "\n"; // 3
    return 0;
}
