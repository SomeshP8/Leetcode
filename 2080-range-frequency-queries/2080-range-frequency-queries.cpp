class RangeFreqQuery {
public:
    vector<map<int,int>>seg;
    int n;
    void build(int id,int low,int high,vector<int>& nums){
        if(low==high){
            seg[id][nums[low]]++;
            return;
        }
        int mid=(low+high)/2;
        build(2*id+1,low,mid,nums);
        build(2*id+2,mid+1,high,nums);
        for(auto &p:seg[2*id+1])
        seg[id][p.first]+=p.second;
        for(auto &p:seg[2*id+2])
        seg[id][p.first]+=p.second;
    }
    int query(int id,int low,int high,int l,int r,int value){
        if(r<low || l>high) return 0;
        if(l<=low && high<=r){
            if(seg[id].count(value))
             return seg[id][value];
            return 0;
        }
        int mid=(low+high)/2;
        return query(2*id+1,low,mid,l,r,value)+query(2*id+2,mid+1,high,l,r,value);
    }
    RangeFreqQuery(vector<int>& arr) {
    n=arr.size();
    seg.resize(4*n);
    build(0,0,n-1,arr);
    } 
    int query(int left, int right, int value) {
        return query(0,0,n-1,left,right,value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */