class Solution {
public:
   bool can(vector<int>& weights,int days,int capacity){
    int dn=1;
    int cn=0;
    for(int weight:weights){
        if(cn+weight > capacity){
            dn++;
            cn=weight;
        }
        else{
            cn+=weight;
        }
    }
    return dn<=days;
   }
    int shipWithinDays(vector<int>& weights, int days) {
       int low=0,high=0;
       for(int weight:weights){
        low=max(low,weight);
        high+=weight;
       }
       int result=high;
       while(low<=high){
        int mid=(low+high)/2;
        if(can(weights,days,mid)){
            result=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
       }
       return result;
   }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna