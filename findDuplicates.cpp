class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(int i : nums){
            if(nums[abs(i)-1] < 0) ans.push_back(abs(i));
            else nums[abs(i)-1] = -nums[abs(i)-1];
        }
        return ans;
    }
};
