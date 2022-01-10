class Solution{
    public:
    string colName (long long int n)
    {
        string s;
        while(n){
            int rem = n%26;
            if(rem==0){
                s.push_back('Z');
                n = n/26-1;
            }
            else{
                char c = 'A'-1;
                s.push_back(c+rem);
                n = n/26;
            }
        }
        reverse(s.begin(),s.end());
        return s;
    }
};