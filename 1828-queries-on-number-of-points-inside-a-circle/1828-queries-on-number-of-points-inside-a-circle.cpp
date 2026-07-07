class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>a;
       // int c=0;
        //int x,y,r;
        for(auto &i:queries){
             int x=i[0],y=i[1],r=i[2];
             int c=0;
             for(auto &j:points){
             int dx=j[0]-x,dy=j[1]-y;
            if((dx*dx + dy*dy) <= r*r){
                c++;
            }
        }
        a.push_back(c);
    }
    return a;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna