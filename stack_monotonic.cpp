#include <iostream>
#include <vector>
#include <stack>

// Next greater element for each item
std::vector<int> nextGreater(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> result(n, -1);
    std::stack<int> st; // stores indices
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}

// Stock span problem
std::vector<int> stockSpan(const std::vector<int>& prices) {
    int n = prices.size();
    std::vector<int> span(n, 1);
    std::stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && prices[st.top()] <= prices[i])
            st.pop();
        span[i] = st.empty() ? i+1 : i - st.top();
        st.push(i);
    }
    return span;
}

// Largest rectangle in histogram
int largestRectangle(const std::vector<int>& heights) {
    std::stack<int> st;
    int maxArea = 0, n = heights.size();
    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        while (!st.empty() && heights[st.top()] > h) {
            int height = heights[st.top()]; st.pop();
            int width  = st.empty() ? i : i - st.top() - 1;
            maxArea = std::max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}

int main() {
    std::vector<int> arr = {4, 5, 2, 10, 8};
    auto ng = nextGreater(arr);
    std::cout << "Next greater: ";
    for (int x : ng) std::cout << x << " "; // 5 10 10 -1 -1
    std::cout << "\n";

    std::vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    auto span = stockSpan(prices);
    std::cout << "Stock span: ";
    for (int x : span) std::cout << x << " "; // 1 1 1 2 1 4 6
    std::cout << "\n";

    std::vector<int> hist = {2, 1, 5, 6, 2, 3};
    std::cout << "Max rectangle: " << largestRectangle(hist) << "\n"; // 10
    return 0;
}
