#include <iostream>
#include <vector>
#include <string>

class KMP {
    std::vector<int> buildLPS(const std::string& pat) {
        int m = pat.size();
        std::vector<int> lps(m, 0);
        int len = 0, i = 1;
        while (i < m) {
            if (pat[i] == pat[len]) { lps[i++] = ++len; }
            else if (len) len = lps[len-1];
            else lps[i++] = 0;
        }
        return lps;
    }

public:
    std::vector<int> search(const std::string& text, const std::string& pat) {
        std::vector<int> lps = buildLPS(pat);
        std::vector<int> matches;
        int n = text.size(), m = pat.size();
        int i = 0, j = 0;
        while (i < n) {
            if (text[i] == pat[j]) { i++; j++; }
            if (j == m) {
                matches.push_back(i - j);
                j = lps[j-1];
            } else if (i < n && text[i] != pat[j]) {
                if (j) j = lps[j-1];
                else i++;
            }
        }
        return matches;
    }
};

int main() {
    KMP kmp;
    std::string text = "AABAACAADAABAABA";
    std::string pat  = "AABA";
    auto res = kmp.search(text, pat);
    std::cout << "Pattern found at indices: ";
    for (int idx : res) std::cout << idx << " "; // 0 9 12
    std::cout << "\n";
    return 0;
}
