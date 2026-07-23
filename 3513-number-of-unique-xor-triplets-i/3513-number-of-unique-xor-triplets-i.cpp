class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
      int n=nums.size();
      if(n==1) return 1;
      if(n==2) return 2;
      return 1<<(__lg(n)+1);  
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna