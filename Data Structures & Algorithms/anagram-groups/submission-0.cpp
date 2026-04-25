class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<vector<string>> output;
        std::unordered_map<string,std::vector<string>> support;

        for(auto& s : strs){
            std::string tmp = s;
            sort(s.begin(),s.end());
            support[s].push_back(tmp);
        }
        for(auto& v : support){
            output.push_back(v.second);
        }
        return output;
    }
};
