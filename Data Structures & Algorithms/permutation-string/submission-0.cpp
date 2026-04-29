class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::vector<int> count1(26, 0);
        std::vector<int> count2(26, 0);
        for (int i  = 0; i < s1.size(); i++){
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
        if (count1 == count2) return true;
        int left = 0;
        int right = 0;
        for ( right = s1.size(); right < s2.size(); right++){
            count2[s2[right] - 'a']++;
            count2[s2[left] - 'a']--;

            left++;
            if(count1 == count2) return true;
        }
        return false;
    }
};




