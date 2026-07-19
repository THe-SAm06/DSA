class Solution {
public:
    void dfs(int node,int& count,vector<vector<int>>& rooms,vector<bool>& vis){
        if(count == rooms.size()) return;
        vis[node] = true;
        count++;

        for(int v:rooms[node]){
            if(!vis[v]){
                dfs(v,count,rooms,vis);
            }
        } 
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int count = 0;
        vector<bool> vis(rooms.size());
        dfs(0,count,rooms,vis);

        return count == rooms.size();
    }
};