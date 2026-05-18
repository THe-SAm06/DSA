class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int count=0;
        vector<pair<int,double>> cars;
        for(int i=0;i<position.size();i++){
            double time = (double)(target - position[i])/speed[i];
            cars.push_back({position[i],time});
        }
        sort(cars.begin(), cars.end());
        double currtime = 0;
        for(int i = cars.size()-1;i>=0;i--){
            if(cars[i].second>currtime){
                count++;
                currtime = cars[i].second;
            }
        }
        return count;
    }
};