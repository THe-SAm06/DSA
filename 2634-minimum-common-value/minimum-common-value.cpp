class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2 = nums2.size();
        if(nums1[0]>nums2[n2-1] || nums2[0]>nums1[n1-1]) return -1;
        int mn = INT_MAX;
        int i=0,j=0,k=0;
        bool found=0;
        while(k<min(n1,n2)){
            while(i<n1 && j<n2 && nums2[j]>nums1[i]) i++;
            while(i<n1 && j<n2 && nums1[i]>nums2[j]) j++;
            if(i<n1 && j<n2 && nums1[i]==nums2[j]){
                mn = min(mn,nums1[i]);
                found=1;
            }
            k++;
        }
        if(found) return mn;
        return -1; 
    }
};