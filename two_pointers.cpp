#include <iostream>
#include <vector>

// Find pair with target sum in sorted array
bool pairSum(const std::vector<int>& arr, int target) {
    int left = 0, right = (int)arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            std::cout << "Pair: " << arr[left] << " + " << arr[right] << "\n";
            return true;
        }
        else if (sum < target) left++;
        else right--;
    }
    return false;
}

// Reverse array in-place
void reverseArray(std::vector<int>& arr) {
    int left = 0, right = (int)arr.size() - 1;
    while (left < right) {
        std::swap(arr[left++], arr[right--]);
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 6, 8, 10};
    pairSum(arr, 10); // Pair: 2 + 8

    std::vector<int> arr2 = {1, 2, 3, 4, 5};
    reverseArray(arr2);
    for (int x : arr2) std::cout << x << " "; // 5 4 3 2 1
    return 0;
}
