class Solution {
public:

    int bs(vector<vector<int>>& matrix, int target, int low, int high){
        if(low>high){
            return -1;
        }
        
        int mid = (high + low)/2;
        if(matrix[mid][0]>target){
            return bs(matrix , target , low, mid-1);
        }
        if(matrix[mid][0]<target && matrix[mid][matrix[0].size()-1]<target){
            return bs(matrix,target,mid+1,high);
        }
        if(matrix[mid][0]<=target && matrix[mid][matrix[0].size()-1]>=target){
            return mid;
        }
        return 0;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()-1;
        int col =matrix[0].size();
        int high = row;
        int low =0;
        int i = bs(matrix,target,low,high);
        if(i==-1){
            return false;
        }
        for(int j=0 ; j<matrix[0].size();j++){
            if(matrix[i][j]==target){
                return true;
            }
        }
        
        return false;
    }
};
