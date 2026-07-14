class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> ind(n,0);
        vector<vector<int>> adj(n);

        for(vector<int> v: pre){
            adj[v[1]].push_back(v[0]);
            ind[v[0]]++;
        }
        vector<int>res;
        queue<int>q;

        for(int i=0 ; i<n ;i++){
            if(ind[i]==0)q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);

            for(int nod : adj[node]){
                ind[nod]--;
                if(ind[nod]==0){
                    q.push(nod);
                }
            }
        }
        if(res.size()==n)return res;

        return {};
    }
};
