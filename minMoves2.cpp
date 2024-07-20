class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int moves = 0;
        sort(nums.begin(), nums.end());
        int mid = nums.size()/2;

        for(int x : nums){
            moves += max(nums[mid], x) - min(nums[mid], x);
        }
        return moves;
    }
};
