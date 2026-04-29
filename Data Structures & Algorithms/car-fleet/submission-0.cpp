class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int,int>>cars;
        for(int i = 0; i < position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        std::sort(cars.rbegin(), cars.rend());
        std::stack<double> fleets;
        for (int i = 0; i < cars.size(); i++) {
            double currTime =(double)(target - cars[i].first) / cars[i].second;
            if (fleets.empty() || currTime > fleets.top()) {
                fleets.push(currTime);
            }
        }
        return fleets.size();
    }
};
