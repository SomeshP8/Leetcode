class Solution {
public:
    int numSteps(string s) {
    int s1=0,carry=0;
    for(int i=s.size()-1;i>0;i--){
    int bit=(s[i]-'0')+carry;
    if(bit==1){
        s1+=2;
        carry=1;
    }
    else{
        s1+=1;
    }
    }
    return s1+carry;
    }
};