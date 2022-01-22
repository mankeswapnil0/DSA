class sgTree{
    vector<int> seg;
public :
    sgTree(int n){
        seg.resize(4*n + 1);
    }
    void build(int ind, int low, int high, vector<int> &v){
        if(low==high){
            seg[ind] = v[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*ind+1, low, mid, v);
        build(2*ind+2, mid+1, high, v);
        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
    }
    int query(int ind, int low, int high, int l, int r){
        // no overlap
        if(low>r || high<l){
            return INT_MAX;
        }
        // full overlap
        if(low>=l && high<=r){
            return seg[ind];
        }
        // partially overlap
        int mid = (low+high)/2;
        int left = query(2*ind+1, low, mid, l, r);
        int right = query(2*ind+2, mid+1, high, l, r);
        return min(left, right);
    }
    void update(int ind, int low, int high, int i, int val){
        if(low==high){
            seg[ind] = val;
            return;
        }
        int mid = (low+high)/2;
        if(i<=mid) update(2*ind+1, low, mid, i, val);
        else update(2*ind+2, mid+1, high, i, val);
        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
    }
};