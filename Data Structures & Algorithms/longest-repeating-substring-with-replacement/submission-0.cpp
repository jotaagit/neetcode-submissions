class Solution {
   public:
    int characterReplacement(string s, int k) {
        int result = 0;
        std::unordered_set<char> charSet(s.begin(), s.end());
        for (char c : charSet) {
            int count = 0;
            int l = 0;
            for (int r = 0; r < s.size(); r++) {
                if (s[r] == c) {
                    count++;
                }
                while ((r - l + 1) - count > k) {
                    if (s[l] == c) {
                        count--;
                    }

                    l++;
                }
                result = std::max(result, r - l + 1);
            }
        }
        return result;
    }
};

// replace most frequent characters in the string;
// number of replacements = s.size() - max_freq;