class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for(char c : tasks){
            freq[c]++;
        }
        priority_queue<int,vector<int>,less<int>> q;

        for(auto& task : freq){
            q.push(task.second);
        }
        int time =0;

        while(!q.empty()){

            int cycle = n+1;
            vector<int> temp;
            int exec =0;

            for(int i=0 ; i<cycle && !q.empty(); i++){
                int count = q.top();
                q.pop();
                if(count>1){
                    temp.push_back(count-1);
                }
                time++;
                exec++;
            }

            for(auto& task: temp){
                q.push(task);
            }

            if(!q.empty()){
                time+=(cycle-exec);
            }




        }
        return time;

    }
};
