
class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       vector<long long int> ans(n, 0);
       long long int zeroCnt = 0;
       int zeroIndex;
       long long int prod = 1;

       for(int i=0; i<n; i++){
           if(nums[i] == 0){
               zeroCnt++;
               zeroIndex = i;
           }
                
           else
                prod *= nums[i];
       }
       
       if(zeroCnt > 1) return ans;
       else if(zeroCnt == 1){
           ans[zeroIndex] = prod;
           return ans;
       }
       
       for(int i=0; i<n; i++){
           ans[i] = prod / nums[i];
       }
       return ans;
    }
};
