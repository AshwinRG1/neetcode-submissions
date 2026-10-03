class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = 0
        res = 0
        seen = set()

        for j in range(len(s)):
            if s[j] not in seen:
                seen.add(s[j])
                res = max(res, j - i + 1)
            else:
                while (s[j] in seen):
                    seen.remove(s[i])
                    i += 1
                seen.add(s[j])
        return res