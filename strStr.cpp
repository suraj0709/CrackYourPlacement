class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        bool flag = false;
        for(int i=0; i<n; i++){
            if(haystack[i] == needle[0]){
                flag = true;
                for(int j=0; j<m; j++){
                    if(needle[j] != haystack[i+j]){
                        flag = false;
                        break;
                    }
                }
                if(flag) return i;
            }
        }
        return -1;
    }
};
