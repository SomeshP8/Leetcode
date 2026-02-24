class NumArray {
public:
    vector<int>seg;
    int n;
    void build(int id,int low,int high,vector<int>& nums){
        if(low==high){
        seg[id]=nums[low];
        return;
        }
        int mid=(low+high)/2;
        build(2*id+1,low,mid,nums);
        build(2*id+2,mid+1,high,nums);
        seg[id]=seg[2*id+1]+seg[2*id+2];
    }
    int query(int id,int low,int high,int l,int r){
        if(r<low || l>high) return  0;
        if(l<=low && high<=r) return seg[id];
        int mid=(low+high)/2;
        return query(2*id+1,low,mid,l,r)+query(2*id+2,mid+1,high,l,r);
    }
    NumArray(vector<int>& nums) {
     n=nums.size();
     seg.resize(4*n);
     build(0,0,n-1,nums);   
    }
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */