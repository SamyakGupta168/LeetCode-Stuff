class DistinctQuery {
    struct Query {
        int l, r, id;
    };

    int n, B;
    vector<int> a, freq, distinctAns, oddAns;
    vector<Query> queries;

    int distinct = 0, odd = 0;

    void add(int x) {
        if (freq[x] == 0) distinct++;
        if (freq[x] & 1) odd--;

        freq[x]++;

        if (freq[x] & 1) odd++;
    }

    void remove(int x) {
        if (freq[x] & 1) odd--;

        freq[x]--;

        if (freq[x] & 1) odd++;
        if (freq[x] == 0) distinct--;
    }

public:
    DistinctQuery(vector<int>& nums, vector<pair<int,int>>& qr) {
        a = nums;
        n = a.size();

        B = max(1, (int)(n / sqrt(qr.size())));

        int q = qr.size();

        queries.resize(q);
        distinctAns.resize(q);
        oddAns.resize(q);

        for (int i = 0; i < q; i++)
            queries[i] = {qr[i].first, qr[i].second, i};

        sort(queries.begin(), queries.end(), [&](const Query& x, const Query& y) {
            int bx = x.l / B;
            int by = y.l / B;

            if (bx != by)
                return bx < by;

            return (bx & 1) ? x.r > y.r : x.r < y.r;
        });

        freq.resize(100001);

        int L = 0, R = -1;

        for (auto [l, r, id] : queries) {
            while (L > l) add(a[--L]);
            while (R < r) add(a[++R]);
            while (L < l) remove(a[L++]);
            while (R > r) remove(a[R--]);

            distinctAns[id] = distinct;
            oddAns[id] = odd;
        }
    }

    int getDistinct(int id) {
        return distinctAns[id];
    }

    int getOdd(int id) {
        return oddAns[id];
    }
};

class Solution {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<pair<int,int>> q;
        for(auto &x : queries) {
            int l = x[0], r = x[1];
            q.push_back({l, r});
        }

        DistinctQuery dq(nums, q);
        vector<bool> ans;
        for(int i=0;i<(int)queries.size();i++) {
            int l = queries[i][0], r = queries[i][1];
            int cnt = dq.getDistinct(i);
            int xr = dq.getOdd(i);
            if(cnt == k && xr == 0) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};