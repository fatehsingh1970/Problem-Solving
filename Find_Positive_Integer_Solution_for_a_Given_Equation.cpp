class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        int x = 1;
        int y = 1000;
        int target;
        vector<vector<int>> res;
        
        while(x <= 1000 && y >= 1){
            target = customfunction.f(x,y);
            if(target == z){
                res.push_back({x,y});
                x++;
                y--;
            } else if(target > z){
                y--;
            } else if(target < z){
                x++;
            }
        }
        
        return res;
    }
};
