class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        
        vector<int> count1(26, 0), count2(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
        
        for (int i = 0; i <= s2.length() - s1.length(); i++) {
            if (count1 == count2) return true;
            if (i + s1.length() < s2.length()) {
                count2[s2[i] - 'a']--;
                count2[s2[i + s1.length()] - 'a']++;
            }
        }
        
        return false;
    }
};