class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> c(A.size(),0);
        vector<int> freq(A.size(),0);
        freq[A[0]-1]++;
        freq[B[0]-1]++;
        if(freq[B[0]-1]==2) c[0]=1;
        else c[0]=0;
        for(int i =1;i<A.size();i++){
            freq[A[i]-1]++;
            c[i]=c[i-1];
            if(freq[A[i]-1]==2) c[i]++;
            freq[B[i]-1]++;
            if(freq[B[i]-1]==2){
                c[i]++;
            } 
        }
        return c;
    }
};