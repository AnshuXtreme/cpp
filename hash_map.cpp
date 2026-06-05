#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

// Frequency count of elements
void frequencyCount(const std::vector<int>& arr) {
    std::unordered_map<int, int> freq;
    for (int x : arr) freq[x]++;
    for (auto& [key, val] : freq)
        std::cout << key << " -> " << val << " times\n";
}

// Check if two strings are anagrams
bool isAnagram(const std::string& a, const std::string& b) {
    if (a.size() != b.size()) return false;
    std::unordered_map<char, int> count;
    for (char c : a) count[c]++;
    for (char c : b) {
        if (!count[c]) return false;
        count[c]--;
    }
    return true;
}

int main() {
    std::vector<int> arr = {1, 2, 2, 3, 3, 3, 4};
    frequencyCount(arr);

    std::cout << isAnagram("listen", "silent") << "\n"; // 1
    std::cout << isAnagram("hello", "world")   << "\n"; // 0
    return 0;
}
