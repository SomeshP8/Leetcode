class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<int>sufsum(n);
        sufsum[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--){
            sufsum[i]=sufsum[i+1]+piles[i];
        }
        vector<vector<int>>memo(n,vector<int>(n+1,0));
        return solve(0,1,piles,sufsum,memo);
    }
    private:
    int solve(int i,int m,vector<int>&piles,vector<int>&sufsum,vector<vector<int>>&memo){
        int n=piles.size();
        if(i>=n) return 0;
        if(i + 2 * m >= n) return sufsum[i];
        if(memo[i][m]!=0) return memo[i][m];
        int maxi=0;
        for(int x=1;x<=2*m;x++){
            int op=solve(i+x,max(m,x),piles,sufsum,memo);
            int our=sufsum[i]-op;
            maxi=max(maxi,our);
        }
        return memo[i][m]=maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna