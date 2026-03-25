class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        vector<int>df;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                df.push_back(i);
            }
        }           
        if(df.size()!=2) return false;
        int i=df[0],j=df[1];
        return (s1[i]==s2[j] && s1[j]==s2[i]);
    }
};