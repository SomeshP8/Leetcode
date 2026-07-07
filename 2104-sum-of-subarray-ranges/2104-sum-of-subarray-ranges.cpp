class Solution {
public:

    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findPSEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        auto nse = findNSE(arr);
        auto psee = findPSEE(arr);

        long long sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            sum += left * right * arr[i];
        }
        return sum;
    }

    vector<int> findNGE(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findPGEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        auto nge = findNGE(arr);
        auto pgee = findPGEE(arr);

        long long sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            long long left = i - pgee[i];
            long long right = nge[i] - i;
            sum += left * right * arr[i];
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long maxSum = sumSubarrayMaxs(nums);
        long long minSum = sumSubarrayMins(nums);
        return maxSum - minSum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna