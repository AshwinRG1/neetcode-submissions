#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int l = 0;
        int max_len = 0;

        for (int r = 0; r < s.length(); r++) {
            while (seen.find(s[r]) != seen.end()) {
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            max_len = max(max_len, r - l + 1);
        }

        return max_len;
    }
};