class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::unordered_map<int,int> map;
        for(int i = 0; i < numbers.size(); i++){
            if(map.count(target-numbers[i])) return {map[target - numbers[i]]+1,i+1};
            map[numbers[i]] = i;
        }
        return {};
    }
};


/*

map[key] = value;

map.count(key) = value;
map.count(numbers[i]) = i;

*/