class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> output;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] == -nums[i]) {
                    std::vector<int> current_triplet = {nums[i], nums[left], nums[right]};
                    if (std::find(output.begin(), output.end(),current_triplet) != output.end()) {
                        left++;
                        right--;
                        continue;
                    }
                    output.push_back(current_triplet);
                }
                if (nums[left] + nums[right] < -nums[i]) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return output;
    }
};
/*
-4,-1,-1,0,1,2

nums[i] + nums[j] + nums[k] == 0
nums[j] + nums[k] == -nums[i]


*/