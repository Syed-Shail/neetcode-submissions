class Solution {
public:

    int numDecodings(string s) {

        int n = s.size();

        // dp[i] = number of ways to decode starting from index i
        vector<int> dp(n + 1, 0);

        // Base case:
        // Reaching the end means we found one valid decoding
        dp[n] = 1;

        // Fill from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Strings starting with 0 are invalid
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }

            // Take one digit
            dp[i] = dp[i + 1];

            // Take two digits if valid
            if (i + 1 < n) {

                int num =
                    (s[i] - '0') * 10 +
                    (s[i + 1] - '0');

                if (num >= 10 && num <= 26) {
                    dp[i] += dp[i + 2];
                }
            }
        }

        return dp[0];
    }
};