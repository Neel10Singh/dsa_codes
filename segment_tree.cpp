class segtree{
  vector<int> seg;
  public:
        segtree(int n){
            seg.resize(n);
        }
        void build(vector<int> &nums, int low, int high, int ind){
            if(low == high){
                seg[ind] = nums[low];
                return;
            }
            int mid = low + (high - low) / 2;
            build(nums, low, mid, 2 * ind + 1);
            build(nums, mid + 1, high,  2 * ind + 2);
            seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
        }
        int find(int ind, int low, int high, int start, int end){
            if(high < start || end < low) return INT_MAX;
            else if(start >= low && end <= high) return seg[ind];
            else{
                int mid = start + (end - start) / 2;
                int left = find(2 * ind + 1, low, high, start, mid);
                int right = find(2 * ind  + 2, low, high, mid + 1, end);
                return min(left, right);
            }
        }
        void change(int ind, int start, int end, int i, int val){
            if(start == end){
                seg[ind] = val;
                return;
            }
            int mid = start + (end - start)/ 2;
            if(i <= mid) change(2 * ind + 1, start, mid, i, val);
            else change(2 * ind + 2, mid + 1, end, i, val);
            seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
        }
  
};
