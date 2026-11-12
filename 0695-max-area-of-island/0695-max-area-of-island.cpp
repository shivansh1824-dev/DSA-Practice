class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int i,int j){
        int count=1;
        int r=grid.size();
        int c=grid[0].size();
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j]==0 || visited[i][j]){
            return 0;
        }
        visited[i][j]=1;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int newR=i+dx[k];
            int newC=j+dy[k];
            count+=dfs(grid,visited,newR,newC);
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxV=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int currMax=dfs(grid,visited,i,j);
                    maxV=max(currMax,maxV);
                }
            }
        }
        return maxV;
    }
};