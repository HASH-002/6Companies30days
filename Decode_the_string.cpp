class Solution{
public:
    string decodedString(string s){
        string ans="";
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]==']'){
                string t="", c="", res="";
                while(st.top()!='['){
                    t = st.top()+t;
                    st.pop();
                }
                st.pop();
                while(!st.empty() && st.top()>='0' && st.top()<='9'){    
                    c = st.top() + c;
                    st.pop();
                }
                int n = stoi(c);
                while(n--)
                    res += t;
                
                if(st.empty())
                    return res;
                
                for(int i=0;i<res.length();i++)
                    st.push(res[i]);
            }
            else
                st.push(s[i]);
        }
        return "";
    }
};