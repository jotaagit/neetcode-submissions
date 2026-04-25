class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> map;
        for(int c : nums){
            if(map.count(c)) return true;
            map.insert(c);
        }
        return false;
    }
};