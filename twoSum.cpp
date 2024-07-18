class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> map;

        for(int i=0; i<nums.size(); i++){
            int temp = target - nums[i];
            if(map.count(temp)){
                ans.push_back(map[temp]);
                ans.push_back(i);
                break;
            }
            map[nums[i]] = i;
        }
        return ans;
    }
};
