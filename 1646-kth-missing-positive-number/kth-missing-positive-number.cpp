class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count = arr[0]-1;
        if(k<=count) return k;
        for(int i = 0;i<arr.size()-1;i++){
            if(count+arr[i+1]-arr[i]-1<k){
                count+=arr[i+1]-arr[i]-1;
            }
            else return arr[i]+k-count;
        }
        return arr[arr.size()-1]+k-count;
    }
};