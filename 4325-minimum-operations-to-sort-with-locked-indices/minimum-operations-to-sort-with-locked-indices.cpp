class Solution {
public:
    long long bubble(int l, int r, vector<int>& nums) {
    int n = nums.size();

    if (l < 0 || r >= n || l >= r) return 0;

    vector<int> temp(nums.begin() + l, nums.begin() + r + 1);
    vector<int> v(temp.size());

    long long swaps = 0;

    function<void(int, int)> mergeSort = [&](int st, int en) {
        if (st >= en) return;

        int mid = (st + en) / 2;

        mergeSort(st, mid);
        mergeSort(mid + 1, en);

        int i = st, j = mid + 1, p = st;

        while (i <= mid && j <= en) {
            if (temp[i] <= temp[j]) {
                v[p++] = temp[i++];
            } else {
                v[p++] = temp[j++];
                swaps += mid - i + 1;
            }
        }

        while (i <= mid) v[p++] = temp[i++];
        while (j <= en) v[p++] = temp[j++];

        for (int x = st; x <= en; x++) {
            temp[x] = v[x];
        }
    };

    mergeSort(0, (int)temp.size() - 1);

    return swaps;
}
    
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        vector<int> has(n+3);
        int m = 1, op = 0;
        vector<int> pos;
        for(int i=0;i<n;i++) {
            if(locked[i]) {
                if(m != i+1 || nums[i] != i+1) {
                    op++;
                } else {
                    pos.push_back(i);
                }
            }
            has[nums[i]] = 1;
            while(has[m]) m++;
        }

        if(op > k) return -1;
        int ans = op, prev = 0;
        for(auto i : pos) {
            ans += bubble(prev, i-1, nums);
            prev = i+1;
        }
        ans += bubble(prev, n-1, nums);

        return ans;
    }
};