#include <iostream>
#include <vector>
#include <string>

// Count set bits
int countBits(int n) {
    int count = 0;
    while (n) { count += n & 1; n >>= 1; }
    return count;
}

// Check if power of 2
bool isPowerOf2(int n) { return n > 0 && (n & (n-1)) == 0; }

// Print all subsets using bitmask
void printPowerSet(const std::vector<int>& arr) {
    int n = arr.size();
    std::cout << "Power set:\n";
    for (int mask = 0; mask < (1 << n); mask++) {
        std::cout << "{ ";
        for (int i = 0; i < n; i++)
            if (mask & (1 << i)) std::cout << arr[i] << " ";
        std::cout << "}\n";
    }
}

// Swap without temp
void swapBits(int& a, int& b) { a ^= b; b ^= a; a ^= b; }

int main() {
    std::cout << "Set bits in 13: " << countBits(13) << "\n";  // 3
    std::cout << "16 power of 2:  " << isPowerOf2(16) << "\n"; // 1
    std::cout << "15 power of 2:  " << isPowerOf2(15) << "\n"; // 0

    int a = 5, b = 9;
    swapBits(a, b);
    std::cout << "Swapped: " << a << " " << b << "\n"; // 9 5

    printPowerSet({1, 2, 3});
    return 0;
}
