class Solution {
public:
    vector<vector<int>> dp;

    bool solve(string& s, string& p, int i, int j) {

        if (j == p.size()) {
            return i == s.size();
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool firstMatch = (i < s.size() &&
                           (s[i] == p[j] || p[j] == '.'));

        bool ans;

        if (j + 1 < p.size() && p[j + 1] == '*') {

            // '*' matches zero characters
            ans = solve(s, p, i, j + 2);

            // '*' matches one or more characters
            if (firstMatch) {
                ans = ans || solve(s, p, i + 1, j);
            }

        } else {
            // Normal character / '.'
            ans = firstMatch && solve(s, p, i + 1, j + 1);
        }

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        dp.assign(s.size() + 1,
                  vector<int>(p.size() + 1, -1));

        return solve(s, p, 0, 0);
    }
};