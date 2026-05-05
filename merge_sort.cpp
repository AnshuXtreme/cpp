#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int l, int m, int r) {
    std::vector<int> L(arr.begin()+l, arr.begin()+m+1);
    std::vector<int> R(arr.begin()+m+1, arr.begin()+r+1);
    int i=0, j=0, k=l;
    while (i<(int)L.size() && j<(int)R.size())
        arr[k++] = (L[i]<=R[j]) ? L[i++] : R[j++];
    while (i<(int)L.size()) arr[k++] = L[i++];
    while (j<(int)R.size()) arr[k++] = R[j++];
}

void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r-l)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22};
    mergeSort(arr, 0, arr.size()-1);
    for (int x : arr) std::cout << x << " ";
    return 0;
}