class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == 1) return {nums[0]};
        std::vector<int> output;
        std::unordered_map<int, int> counter;  // will store value and frequency
        int reachK = 0;
        int i = 0;
        for (int c : nums) {
            counter[c]++;
        }

        int delete_key = 0;
        while (reachK != k) {
            int max_freq = 0;
            for (const auto& par : counter) {
                if (par.second > max_freq) {
                    max_freq = par.second;
                    delete_key = par.first;
                }
            }
            output.push_back(delete_key);
            counter.erase(delete_key);
            reachK++;
        }
        return output;
    }
};

/*
    int freq = map[c]
    map[key] = value;
    map[value]
    key (unique)        value
        c              frequency

    counter[c] = value
    par.first = key ( algarismo )
    par.second = value ( frequencia )







*/
