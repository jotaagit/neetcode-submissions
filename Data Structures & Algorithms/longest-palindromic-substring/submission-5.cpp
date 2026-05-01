class Solution {
public:
    bool isPalindrome(string sub){
        if(sub.size()== 1) return true;
        int left = 0;
        int right = sub.size() - 1;
        while(left <=right){
            if(!(sub[right] == sub[left])) return false;
            left++;
            right--;
        }
        return true;

    }
    
    string longestPalindrome(string s) {
        if(s.size()<=1) return s;
        std::string result = "";
        for(int i = 0; i < s.size(); i++){
            for(int j = 1; j <= s.size() - i; j++){
                string currSub = s.substr(i,j);
                if(isPalindrome(currSub)){
                    if(result.size() < currSub.size()){
                        result = currSub;
                    }
                }
            }
        }
        return result;

    }
};
