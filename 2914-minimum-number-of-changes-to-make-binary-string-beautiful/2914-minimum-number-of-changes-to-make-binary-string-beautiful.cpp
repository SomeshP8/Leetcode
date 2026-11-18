class Solution {
public:
    int minChanges(string s) {
        int c=0;
        for(int i=0;i<s.length();i+=2){
            c+=(s[i]!=s[i+1]);
        }
        return c;
    }
};





// class Solution {
// public:
//     int minChanges(string s) {
//         int flag=0;
//         for (int i=0;i<s.length();i+=2)
//             if(s[i]!=s[i+1]) flag++;
//         return flag;
//     }

// };

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna