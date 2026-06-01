#include <iostream>
#include <vector>
#include <climits>

int maxSubarraySum(const std::vector<int>& arr) {
    int maxSum = INT_MIN, curSum = 0;
    int start = 0, end = 0, tempStart = 0;
    for (int i = 0; i < (int)arr.size(); i++) {
        curSum += arr[i];
        if (curSum > maxSum) {
            maxSum = curSum;
            start = tempStart;
            end = i;
        }
        if (curSum < 0) {
            curSum = 0;
            tempStart = i + 1;
        }
    }
    std::cout << "Subarray: ";
    for (int i = start; i <= end; i++) std::cout << arr[i] << " ";
    std::cout << "\n";
    return maxSum;
}

int main() {
    std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << "Max Sum: " << maxSubarraySum(arr) << "\n"; // 6
    return 0;
}
