class Solution:
    def minWindow(self, s: str, t: str) -> str:
        n = len(s)
        res = ""
        set_t = set(t)
        for i in range(n):
            for j in range(i, n):
                set_s = set(s[i:j])
                if set_s.intersection(set_t) == set_t:
                    temp = s[i:j]
                    res = min(res, temp)

        return res

