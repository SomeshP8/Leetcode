class Solution {
public:
    bool rotateString(string a, string b) {
        return a.size()==b.size() && (a+a).find(b)!=-1;
    }
};
