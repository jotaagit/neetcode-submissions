class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> arr(std::begin(nums),std::end(nums));
        int steps = 0;
        for(int num : arr){
            if(!arr.contains(num - 1)){     
                int start = num;
                int current_steps = 1;
                while(arr.contains(start + 1)){
                    start++;
                    current_steps++;
                }
                steps = std::max(steps,current_steps);
            }
        }
        return steps;
    }
};
