class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string ans = "";

        for(int i=0; i<s.size(); i++){
            while(i < s.size() && s[i] == ' ')
                i++;
            string temp = "";
            while(i < s.size() && s[i] != ' '){
                temp += s[i];
                i++;
            }
            if(temp.size() > 0) words.push_back(temp);
        }
        for(string w : words){
            if(ans.size() == 0)
                ans += w;
            else
                ans = w + " " + ans;
        }
        return ans;
    }
};
