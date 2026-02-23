class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string>st;
        for(int i=0;i+k<=s.size();i++){
            st.insert(s.substr(i, k));
            
            if (st.size() == (1 << k))
               return true;
        }
        return st.size()==(1<<k);
    }
};