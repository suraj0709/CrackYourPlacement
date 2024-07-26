class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> res;
        deque<int> dq;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(!dq.empty() && dq.front() <= i-k)
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i >= k-1)
                res.push_back(nums[dq.front()]);
        }
        return res;


        //Brute Force Approach : TLE
        // vector<int> res;
        // int n = nums.size();

        // for(int i=0; i<=n-k; i++){
        //     int maxi = nums[i];
        //     for(int j=i; j<=(i+k-1); j++){
        //         maxi = max(nums[j], maxi);
        //     }
        //     res.push_back(maxi);
        // }
        // return res;
    }
};
