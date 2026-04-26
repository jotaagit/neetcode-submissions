class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> helper = nums;
        std::vector<int> output(nums.size());
        for(int i = 0; i < nums.size(); ++i){
            int total = 1;
            int original = helper[i];
            helper[i] = 1;
            for(int j = 0; j < helper.size(); ++j){
                total = total * helper[j];
            }
            output[i] = total;
            helper[i] = original;
        }
        return output;
    }
};