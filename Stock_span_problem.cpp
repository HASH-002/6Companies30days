class Solution
{
    public:
    vector <int> calculateSpan(int a[], int n)
    {
        vector<int>v;
        v.push_back(1);
        stack<int>s;
        s.push(0);
        int i=1;
        while(i<n){
            while(!s.empty() && a[s.top()]<=a[i])
                s.pop();
            
            if(!s.empty())
                v.push_back(i-s.top());
            else
                v.push_back(i+1);
            s.push(i);
            i++;
        }
        return v;
    }
};