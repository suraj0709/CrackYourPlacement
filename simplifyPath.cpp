class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        stack<string> st;
        int n = path.size();

        for(int i=0; i<n; i++){
            string temp = "";
            if(path[i] == '/') continue;
            while(i<n && path[i] != '/'){
                temp += path[i];
                i++;
            }
            if(temp == ".") continue;
            if(temp == ".."){
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(temp);
        }
        if(st.empty())
            return "/";
            
        while(!st.empty()){
            res = '/' + st.top() + res;
            st.pop();
        }
                
        return res;        
    }
};
