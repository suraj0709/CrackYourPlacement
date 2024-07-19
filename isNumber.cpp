class Solution {
public:
    bool isNumber(string s) {
        bool digitSeen = false, dotSeen = false, eSeen = false;
        int signCnt = 0;

        for(int i=0; i<s.size(); i++){
            //digit
            if(s[i] >= '0' && s[i] <= '9')
                digitSeen = true;
            //plus/minus
            else if(s[i] == '-' || s[i] == '+'){
                if(signCnt == 2 || i == s.size()-1)
                    return false;
                if(i>0 && s[i-1] != 'e' && s[i-1] != 'E')
                    return false;
                signCnt++;
            }
            //dot
            else if(s[i] == '.'){
                if(dotSeen || eSeen)
                    return false;
                if(i == s.size()-1 && !digitSeen)
                    return false;
                dotSeen = true;
            }
            
            //E/e
            else if(s[i] == 'e' || s[i] == 'E'){
                if(eSeen || !digitSeen || i == s.size()-1)
                    return false;
                eSeen = true;
            }
            else return false;
        }
        return true;
    }
};
