class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        unordered_map<string,int>mp;
        string str="";
        for(int i=0;i<s.size();i++){
            str.push_back(s[i]);
            if(i>=9){
              if(mp.count(str) and mp[str]==1){
                 ans.push_back(str);
              }
              mp[str]++;
              str.erase(str.begin());
            }
        }
      return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna