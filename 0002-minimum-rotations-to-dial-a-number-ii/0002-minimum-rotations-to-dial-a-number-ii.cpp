class Solution {
public:
    int get(int a,int b){
        int diff=abs(a-b);
        return min(diff,10-diff);
    }
    int minRotations(int n, string s) {
        int base=0,curr=0;
        for(char c:s){
            int target=c-'0';
            base+=get(curr,target);
            curr=target;
        }
        int mini=base;
        int last=s[n-1]-'0';
        for(int k=0;k<n;k++){
            int modify=base;
            if(k==0){
                int original=s[0]-'0';
                modify-=get(0,original);
                modify+=get(0,last);
            }
            else{
                int prev=s[k-1]-'0';
                int ok=s[k]-'0';
                modify-=get(prev,ok);
                modify+=get(prev,last);
            }
            mini=min(mini,modify);
        }
        return mini;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna