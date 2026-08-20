class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==1) return {{1}};
        int ri = n-1;
        int li = 0;

        int ui = 0;
        int di = n-1;

        vector<vector<int>> ans(n,vector<int>(n,0));
        int k = 1;

        while(ui<=di && ri>=li){
            for(int j = li;j<=ri;j++){
                ans[ui][j] = k++;
            }
            ui++;
            for(int i = ui;i<=di;i++){
                ans[i][ri] = k++;
            }
            ri--;
            for(int j = ri;j>=li;j--){
                ans[di][j] = k++;
            }
            di--;
            for(int i = di;i>=ui;i--){
                ans[i][li] = k++;
            }
            li++;
        }
        return ans;
    }
};