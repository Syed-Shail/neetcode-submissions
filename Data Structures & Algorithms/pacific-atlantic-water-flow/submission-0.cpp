class Solution {
public:
      void trav(vector<vector<int>>& heights,
              vector<vector<int>>& mark,
              int i, int j, int high, int m) {
        
        if (i < 0 || i >= heights.size() ||
            j < 0 || j >= heights[0].size() ||
            heights[i][j] < high)
            return;

        int t = mark[i][j];


        if (t == m || t == -3) return;


        if ((t == -1 && m == -2) || (t == -2 && m == -1))
            mark[i][j] = -3;
        else
            mark[i][j] = m;

        int curr = heights[i][j];

        trav(heights, mark, i + 1, j, curr, m);
        trav(heights, mark, i - 1, j, curr, m);
        trav(heights, mark, i, j + 1, curr, m);
        trav(heights, mark, i, j - 1, curr, m);
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> mark(rows, vector<int>(cols, 0));


        for (int j = 0; j < cols; j++) {
            trav(heights, mark, 0, j, INT_MIN, -1);
        }


        for (int i = 0; i < rows; i++) {
            trav(heights, mark, i, 0, INT_MIN, -1);
        }

     
        for (int j = 0; j < cols; j++) {
            trav(heights, mark, rows - 1, j, INT_MIN, -2);
        }

 
        for (int i = 0; i < rows; i++) {
            trav(heights, mark, i, cols - 1, INT_MIN, -2);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mark[i][j] == -3) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
