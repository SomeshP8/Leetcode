class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c:s){
            switch(c){
                case '(': st.push(')');
                break;
                case '[': st.push(']');
                break;
                case '{': st.push('}');
                break;
                default:
                if(st.empty()||st.top()!=c){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna