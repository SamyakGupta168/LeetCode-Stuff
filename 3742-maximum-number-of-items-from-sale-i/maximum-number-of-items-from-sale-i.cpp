class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> bounties(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (items[j][0] % items[i][0] == 0) bounties[i]++;
            }
        }

        // dp[i][b] tracks maximum items up to item index i with budget b
        vector<vector<int>> dp(n + 1, vector<int>(budget + 1, 0));

        for (int i = 1; i <= n; i++) {
            int price = items[i - 1][1];
            int bounty = bounties[i - 1];

            // Initialize row with values from the previous item (not taking item i)
            for (int b = 0; b <= budget; b++) {
                dp[i][b] = dp[i - 1][b];
            }

            // Pass A: Activation (Buy at least once)
            // Uses dp[i-1] because it transitions from a state where item i wasn't bought
            for (int b = budget; b >= price; b--) {
                dp[i][b] = max(dp[i][b], dp[i - 1][b - price] + bounty);
            }

            // Pass B: Exploitation (Buy multiple extra copies)
            // Uses dp[i] because it builds upon previous purchases of the same item i
            for (int b = price; b <= budget; b++) {
                dp[i][b] = max(dp[i][b], dp[i][b - price] + 1);
            }
        }

        return dp[n][budget];
    }
};