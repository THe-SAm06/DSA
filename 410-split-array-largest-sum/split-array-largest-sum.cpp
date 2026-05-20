class Solution {
public:
bool poss(vector<int> &nums, int k,int n){
        int currk = 1;
        int sum = 0;
        for(int a:nums){
            if(sum+a<=n){
                sum+=a;
            }
            else{
                sum = a;
                currk++;
            }
        }
        if(currk<=k) return true;
        return false;
    }

    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size()) return -1;
        int left = *max_element(nums.begin(),nums.end());
        int right=0;
        for(int a:nums) right+=a;
        while(left<right){
            int mid=left+(right-left)/2;
            if(poss(nums,k,mid)) right=mid;
            else left=mid+1;
        }
        return left;
    }
};