class Solution {
public:
    vector<int>findNSE(vector<int> &arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            int currEle=arr[i];
            while(!st.empty() && arr[st.top()]>=arr[i]){
               st.pop();
            }
            ans[i]=!st.empty()?st.top():n;
            st.push(i);
        }
        return ans;
    }
    vector<int>findPSEE(vector<int> &arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            int currEle=arr[i];
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i]=!st.empty()?st.top():-1;
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>findnse=findNSE(arr);
        vector<int>findpsee=findPSEE(arr);
        int n=arr.size();
        int mod=1e9+7;
        int sum=0;
        for(int i=0;i<n;i++){
            int left=i-findpsee[i];
            int right=findnse[i]-i;
            long long freq=left*right*1LL;
            int val=(freq*arr[i]*1LL)%mod;
            sum=(sum+val)%mod;
         }
         return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna