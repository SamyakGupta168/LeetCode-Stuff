class Solution {
public:
    static constexpr long long LIM = 1000001;

    long long nCk(int n, int k) {
        if (k > n) return 0;
        k = min(k, n - k);

        long long ans = 1;
        for (int i = 1; i <= k; i++) {
            ans = ans * (n - i + 1) / i;
            if (ans >= LIM) return LIM;
        }
        return ans;
    }

    long long countWays(vector<int>& cnt) {
        int rem = 0;
        for (int x : cnt) rem += x;

        long long ways = 1;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) continue;
            ways *= nCk(rem, cnt[i]);
            if (ways >= LIM) return LIM;
            rem -= cnt[i];
        }

        return ways;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26);

        for (char c : s)
            freq[c - 'a']++;

        string mid = "";

        for (int i = 0; i < 26; i++) {
            if (freq[i] & 1)
                mid.push_back(char('a' + i));
            freq[i] /= 2;
        }

        if (countWays(freq) < k)
            return "";

        string left = "";

        int len = 0;
        for (int x : freq) len += x;

        while (len--) {
            for (int c = 0; c < 26; c++) {
                if (freq[c] == 0) continue;

                freq[c]--;

                long long ways = countWays(freq);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                freq[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};