class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {

        // let say the color of grid is like WBWBWBWB so every cell with i+j as  even is w and odd is b;
        // knight always changes color in one move W->B or B->W;
        // so they must be in same color so that start reaches target in even moves;

        int color_start = (start[0]+start[1])%2; 
        int color_target = (target[0]+target[1])%2; 

        return color_start == color_target;
    }
};