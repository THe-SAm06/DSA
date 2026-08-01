class Solution {
public:
    bool fun(int i,int j,vector<int>& nums,int score1,int score2,bool turn1){
        if(i>j) return score1>=score2;
        if(turn1){
            if(fun(i+1,j,nums,score1+nums[i],score2,!turn1) || fun(i,j-1,nums,score1+nums[j],score2,!turn1)) return true;
        }
        else{
            if(fun(i+1,j,nums,score1,score2+nums[i],!turn1) && fun(i,j-1,nums,score1,score2+nums[j],!turn1)) return true;
        }
        return false;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return fun(0,n-1,nums,0,0,true);
    }
};