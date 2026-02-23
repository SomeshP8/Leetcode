class Solution {
public:
    string maximumXor(string s, string t) {
        int n = s.length();
        int c0 = 0, c1 = 0;
        for (char c : t) {
            if (c == '0') c0++;
            else c1++;
        }
        string res = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (c1 > 0) {
                    res += '1';
                    c1--;
                } else {
                    res += '0';
                    c0--;
                }
            } else { 
                if (c0 > 0) {
                    res += '1';
                    c0--;
                } else {
                    res += '0';
                    c1--;
                }
            }
        }
        return res;
    }
};