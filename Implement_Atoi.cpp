class Solution{
  public:
    int atoi(string s) {
        int i=0, n=0;
        int flag = 1;
        if(s[0]=='-'){
            flag = -1;
            i++;
        }else if(s[i]=='+')
            i++;
            
        while(i<s.length()){
            if(s[i]<'0' || s[i]>'9')
                return -1;
            n = n*10 +(s[i]-'0');
            i++;
        }
        return n*flag;
    }
};