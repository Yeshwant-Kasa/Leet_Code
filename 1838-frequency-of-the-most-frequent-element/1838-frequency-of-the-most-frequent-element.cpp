class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long left =0, right =0, maxFreq = 1, totalCost=0;
        while (right<nums.size()){
            if (right>0){
                totalCost += (right -left)* (nums[right] - nums[right-1]); // increasing total cost to make nums[] all equal nums[r]
            }
            
            while (totalCost >k){ //cost exceeding k shrink window size
                totalCost -=(nums[right] - nums[left]);//removing left element contribution
                left++;   
            }

            maxFreq = max(maxFreq,right-left+1); //largest window size
            right++;
        } 
        return maxFreq;
    }
};