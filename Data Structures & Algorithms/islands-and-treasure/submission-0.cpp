class Solution {
public:
    void trav(vector<vector<int>>& grid, int i , int j, int dis){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()|| grid[i][j]==-1 || (dis > 0 && grid[i][j] <= dis))return;
        
        grid[i][j]=dis;

        trav(grid,i+1,j,dis+1);
        trav(grid,i-1,j,dis+1);
        trav(grid,i,j+1,dis+1);
        trav(grid,i,j-1,dis+1);

        return;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i =0 ; i<grid.size();i++){
            for(int j=0 ; j<grid[0].size();j++){
                if(grid[i][j]==0){
                    trav(grid,i,j,0);
                }
            }
        }
    }
};
