class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::unordered_set<int> checked;
        for(int num : nums){
            if(checked.count(num))return num;
            checked.insert(num);
        }
        return -1;
    }
};
