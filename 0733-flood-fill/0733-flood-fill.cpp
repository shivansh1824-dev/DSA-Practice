class Solution {
public:
    void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, int sr, int sc, int color, int originalColor) {
        int r = image.size();
        int c = image[0].size();

        if (sr < 0 || sc < 0 || sr >= r || sc >= c ||
            ans[sr][sc] != originalColor) {
            return;
        }
        ans[sr][sc] = color;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++) {
            int newR = sr + dx[k];
            int newC = sc + dy[k];
            dfs(image, ans, newR, newC, color, originalColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int originalColor = image[sr][sc];
        if (color == originalColor) {
            return ans;
        }
        dfs(image, ans, sr, sc, color, originalColor);
        return ans;
    }
};