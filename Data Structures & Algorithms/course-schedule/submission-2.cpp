class Solution {
public:
    vector<int> state;
    vector<vector<int>>adj;

    bool dfs(int i){
        if(state[i]==1)return false;
        if(state[i]==2)return true;
        state[i]=1;
        for(int n: adj[i]){
            if(!dfs(n))return false;
        }
        state[i]=2;
        return true;
    }

    bool canFinish(int n, vector<vector<int>>& pre) {
        state.resize(n,0);
        adj.resize(n);
        for(vector<int> v : pre){
            adj[v[1]].push_back(v[0]);
        }
        for(int i=0 ; i<n ; i++){
            if(!dfs(i))return false;
        }
        return true;
    }
};
