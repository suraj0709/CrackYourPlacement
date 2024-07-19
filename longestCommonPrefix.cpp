class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size()-1;
        string ans = "";

        sort(strs.begin(), strs.end());

        int m = min(strs[0].size(), strs[n].size());
        for(int i=0; i<m; i++){
            if(strs[0][i] == strs[n][i])
                ans += strs[0][i];
            else
                return ans;
        }
        return ans;
    }
};
