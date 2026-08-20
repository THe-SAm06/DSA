class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> l;
        vector<int> r;
        
        l.push_back(nums[0]);
        r.push_back(nums[1]);

        int k = 2;
        while(k<n){
            if(l.back()>r.back()){
                l.push_back(nums[k]);
            }
            else{
                r.push_back(nums[k]);
            }
            k++;
        }
        l.insert(l.end(),r.begin(),r.end());
        return l;
    }
};