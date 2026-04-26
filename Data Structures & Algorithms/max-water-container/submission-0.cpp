class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0; int right = heights.size() - 1;
        int water = 0;
        while(left < right){
            int smalCol = std::min(heights[left],heights[right]);
            water = std::max(water,smalCol * (right - left));
            if(heights[left] < heights[right]){
                left++;
            }
            else right = right - 1;
        }
        return water;
    }
};