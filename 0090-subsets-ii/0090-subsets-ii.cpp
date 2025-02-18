class Solution {
public:
    void findSubsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result){
        result.push_back(current); // store the currrent value


        for(int i=index; i<nums.size();i++){
            
            if(i>index && nums[i] == nums[i-1]) continue; //skipping duplicates to prevent duplicate subsets

            current.push_back(nums[i]);// include nums[i] in the subset.

            findSubsets(i+1, nums, current, result);// recursive calls for next elements

            current.pop_back(); //backtrack: remove last name before the next iteration
        }
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        // sort-handle duplicates
        sort(nums.begin(), nums.end());
        //backtrack to generate subsets
        findSubsets(0, nums, current, result);
        return result;

        
    }
};

