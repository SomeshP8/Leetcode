class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    int n=nums.size();
     int c1=0,c2=0;
     int e1=INT_MIN,e2=INT_MIN;
     for(int i=0;i<n;i++){
        if(c1==0 && nums[i]!=e2){
            c1=1;
            e1=nums[i];
        }
        else if(c2==0 && nums[i]!=e1){
            c2=1;
            e2=nums[i];
        }
        else if(e1==nums[i]) c1++;
        else if(e2==nums[i]) c2++;
        else{
            c1--;
            c2--;
        }
     }
     vector<int>ls;
     c1=0,c2=0;
     for(int i=0;i<n;i++){
        if(e1==nums[i]) c1++;
        if(e2==nums[i]) c2++;
     }
     int mini=(n/3)+1;
     if(c1>=mini) ls.push_back(e1);
     if(c2>=mini) ls.push_back(e2);
     sort(ls.begin(),ls.end());
     return ls;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna