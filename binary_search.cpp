#include <iostream>
#include <vector>

class BinarySearch {
public:
    static int search(const std::vector<int>& arr, int target) {
        int left = 0, right = (int)arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11};
    std::cout << BinarySearch::search(arr, 7) << std::endl; // 3
    return 0;
}