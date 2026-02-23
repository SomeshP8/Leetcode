class Solution {
public:
    bool isDigitorialPermutation(int n) {
        int fact[10];
        fact[0]=1;
        for(int i=1;i<10;i++){
            fact[i]=fact[i-1]*i;
        }
        string s=to_string(n);
        int total=0;
        for(char c:s){
            total+=fact[c-'0'];
        }
      string t=to_string(total);
      if(t.length()!=s.length()) return false;
      vector<int> count1(10, 0), count2(10, 0); 
        for(char c:s)
            count1[c-'0']++;
        for(char c:t)
            count2[c-'0']++;
        return count1 == count2;
    }
};