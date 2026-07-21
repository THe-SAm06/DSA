class Solution {
private:
    void sieve(vector<int>& spf){
        int n = spf.size();
        for(int i = 1;i<n;i++) spf[i] = i;
        for(int i =2;i*i<n;i++){
            if(spf[i] == i){
                for(int j = i*i;j<n;j+=i){
                    if(spf[j] == j) spf[j] = i;
                }
            }
        }
    }
public:
    int minJumps(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int mx = *max_element(nums.begin(),nums.end());
        vector<int> spf(mx+1);
        sieve(spf);
        unordered_map<int,vector<int>> primes;

        for(int i = 0;i<nums.size();i++){
            int temp = nums[i];
            while(temp>1){
                int p = spf[temp];
                primes[p].push_back(i);
                while(temp % p == 0) temp /= p;
            }
        }
        vector<bool> vis(nums.size());
        queue<int> q;
        q.push(0);
        vis[0] = true;

        int steps = 0;

        while(!q.empty()){
            int s = q.size();
            while(s--){
                int node = q.front();
                q.pop();

                if(node == nums.size()-1) return steps;

                for(int i: {node-1,node+1}){
                    if(i>=0 && i<nums.size() && !vis[i]){
                        q.push(i);
                        vis[i] = true;
                    }
                }

                if(spf[nums[node]] == nums[node] && primes.count(nums[node])){
                    for(int i: primes[nums[node]]){
                        if(!vis[i]){
                            vis[i] = true;
                            q.push(i);
                        }
                    }
                    primes.erase(nums[node]);
                }
            }
            steps++;
        }
        return -1;
    }
};