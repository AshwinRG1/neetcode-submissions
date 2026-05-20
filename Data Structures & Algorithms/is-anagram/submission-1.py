class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        freqS = Counter(s)
        freqT = Counter(t)
        

        if freqS == freqT:
            return True
        else:
            return False
