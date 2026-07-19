class Solution {
public:
    string smallestSubsequence(string s) {
         vector<int>last(26,0);
         vector<bool>seen(26,false);
         string result="";
         for(int i=0;i<s.length();i++){
            last[s[i]-'a']=i;
         }
         for(int i=0;i<s.length();i++){
            char c=s[i];
            if(seen[c-'a']) continue;
            while(!result.empty() && result.back()>c && last[result.back()-'a']>i){
                seen[result.back()-'a']=false;
                result.pop_back();
            }
            result.push_back(c);
            seen[c-'a']=true;
         }
         return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna