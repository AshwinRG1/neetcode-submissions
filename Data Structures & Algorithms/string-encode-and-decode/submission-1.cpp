class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (string str : strs){
            int los = str.length();
            res.append(to_string(los));
            res += "$";
            res.append(str);
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.length()) {
            int delimiter = s.find('$', i);
            int length = stoi(s.substr(i, delimiter - i));
            i = delimiter + 1; 
            res.push_back(s.substr(i, length));
            i += length; 
        }
        return res;
        
    }
};
