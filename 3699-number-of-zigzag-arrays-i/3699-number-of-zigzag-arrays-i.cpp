class Solution {
public:
    int MOD=1e9+7;
    int zigZagArrays(int n, int l, int r) {
        int m=r-l+1;
        vector<vector<int>>up(n+1,vector<int>(m,0));
        vector<vector<int>>down(n+1,vector<int>(m,0));
        for(int x=0;x<m;x++){
            for(int y=0;y<m;y++){
                if(x==y) continue;
                if(x<y)
                up[2][y]=(up[2][y]+1)%MOD;
                else
                down[2][y]=(down[2][y]+1)%MOD;
            }
        }
    for(int i=3;i<=n;i++){
        vector<int>prefUP(m+1,0),prefDOWN(m+1,0);
        for(int v=0;v<m;v++){
            prefUP[v+1]=(prefUP[v]+up[i-1][v])%MOD;
            prefDOWN[v+1]=(prefDOWN[v]+down[i-1][v])%MOD;
        }
        for(int y=0;y<m;y++){
            up[i][y]=prefDOWN[y];
            down[i][y]=((prefUP[m]-prefUP[y+1])%MOD+MOD)%MOD;
        }
    }
        long long ans=0;
        if(n==1){
            ans=m;
        }
        else{
            for(int y=0;y<m;y++){
                ans=(ans+up[n][y]+down[n][y])%MOD;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna