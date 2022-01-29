class compare {
   public:
    bool operator()(string& a, string& b) {
        if (a.length() != b.length())
            return a.length() > b.length();
        return a > b;
    }
};
class Solution {
   public:
    string kthLargestNumber(vector<string>& a, int k) {
        priority_queue<string, vector<string>, compare> q;
        for (int i = 0; i < a.size(); i++) {
            q.push(a[i]);
            if (q.size() > k)
                q.pop();
        }
        return q.top();
    };
};