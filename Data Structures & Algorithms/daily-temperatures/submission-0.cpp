class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> temps;
        std::vector<int> result(temperatures.size(),0);
        for(int i = 0; i < temperatures.size(); i++){
            int diff = 0;
            while(!temps.empty() && temperatures[temps.top()] < temperatures[i]){
                diff = i - temps.top();
                result[temps.top()] = diff;
                temps.pop();
            }
            temps.push(i); 
        }
        return result;
    }
};
