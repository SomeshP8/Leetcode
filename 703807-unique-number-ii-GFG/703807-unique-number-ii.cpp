class Solution {
public:
vector<int> singleNum(vector<int>& nums) {
    long long xorAll = 0;
    for (int x : nums)
        xorAll ^= x;
    long long diffBit = xorAll & (-xorAll);
    int a = 0, b = 0;
    for (int x : nums) {
        if (x & diffBit)
            a ^= x;
        else
            b ^= x;
    }
     if (a > b) swap(a, b); 
    return {a, b};
}
};