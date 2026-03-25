class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s1=0,s2=0;
        for(int x:gas) s1+=x;
        for(int x:cost) s2+=x;
        if(s1<s2) return -1;
        int total_gas=0,curr=0,start=0;
        for(int i=0;i<gas.size();i++){
            int diff=gas[i]-cost[i];
            total_gas+=diff;
            curr+=diff;
            if(curr<0){
                curr=0;
                start=i+1;
            }
        }
        return (total_gas<0) ? 0 : start;
    }
};