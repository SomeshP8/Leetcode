class Solution {
public:
    string minWindow(string s, string t) {
     vector<int>hash(256,0);
     int l=0,r=0,mini=INT_MAX,sidx=-1,cnt=0;
     int n=s.size(),m=t.size();
     for(int i=0;i<m;i++){
        hash[t[i]]++;
     } 
     while(r<n){
        if(hash[s[r]]>0) cnt++;
        hash[s[r]]--;
        while(cnt==m){
            if(r-l+1 < mini){
                mini=r-l+1;
                sidx=l;
            }
            hash[s[l]]++;
            if(hash[s[l]]>0) cnt--;
            l++;
        }
        r++;
     }
     return sidx==-1 ? "":s.substr(sidx,mini);
    }
}; 

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna