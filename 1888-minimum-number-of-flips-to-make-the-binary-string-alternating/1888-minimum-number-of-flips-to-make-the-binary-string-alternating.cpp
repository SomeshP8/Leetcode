class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        s=s+s;
        string s1="";
        string s2="";
        for(int i=0;i<n;i++){
            if(i%2==0){
                s1+="0";
                s2+="1";
            }
            else{
                s1+="1";
                s2+="0";
            }
        }
        int d1=0,d2=0;
        int left=0;
        int ans=INT_MAX;
        for(int right=0;right<n;right++){
            if(s[right]!=s1[right]) d1++;
            if(s[right]!=s2[right]) d2++;
            if(right-left+1>n){
                if(s[left]!=s1[left]) d1--;
                if(s[left]!=s2[left]) d2--;
            }
            if(right-left+1==n){
                ans=min(ans,min(d1,d2));
            }
        }
        return ans;
    }
};