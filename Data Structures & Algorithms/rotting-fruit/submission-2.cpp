class Solution {
public:

    void trav(vector<vector<int>>& grid , int i , int j , int dis){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0 || grid[i][j]==-2)return;
        if(dis>=grid[i][j])return;
        grid[i][j]=min(dis,grid[i][j]);
        trav(grid,i+1,j,dis+1);
        trav(grid,i-1,j,dis+1);
        trav(grid,i,j+1,dis+1);
        trav(grid,i,j-1,dis+1);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res=0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]==1)grid[i][j]=INT_MAX;
                if(grid[i][j]==2)grid[i][j]=-2;
            }
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]==-2){
                    trav(grid,i+1,j,1);
                    trav(grid,i-1,j,1);
                    trav(grid,i,j+1,1);
                    trav(grid,i,j-1,1);
                }
            }
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]==INT_MAX)return -1;
                res=max(res,grid[i][j]);
            }
        }
        return res;

    }
};
