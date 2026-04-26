class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        //if(s.empty()) return 0;
        //if(s.size()==1) return 1;
        int left = 0;
        int right = 0;
        int maxSubstring = 0;
        std::unordered_set<char> checked;
        for (right = 0; right < s.size(); right++) {
            while (checked.find(s[right]) != checked.end()) {
                checked.erase(s[left]);
                left++;
            }
            checked.insert(s[right]);
            maxSubstring = std::max(maxSubstring,right - left + 1);
       }

       return maxSubstring;
    }
};
