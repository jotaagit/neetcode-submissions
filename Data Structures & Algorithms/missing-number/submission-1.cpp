class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::unordered_set<int> check(std::begin(nums),std::end(nums));
        int missing = 0;
        for(int i = 0; i < nums.size() + 1
        ; i++){
            if(check.contains(i)) continue;
            missing = i;
        }
        return missing;
    }
};
