class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;

        for(char c : s){
            if(c == '#' && s1.empty()) continue;
            if(c == '#') s1.pop();
            else s1.push(c);
        }
        for(char c : t){
            if(c == '#' && s2.empty()) continue;
            if(c == '#') s2.pop();
            else s2.push(c);
        }
        
        return s1 == s2;
    }
};
