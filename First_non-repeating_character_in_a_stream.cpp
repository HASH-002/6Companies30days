class Solution {
	public:
		string FirstNonRepeating(string s){
		    int a[26] = {0};
		    queue<char>q;
		    string ans="";
		    for(int i=0;i<s.length();i++){
	            q.push(s[i]);
	            a[s[i]-'a']++;
		        while(!q.empty() && a[q.front()-'a']>1)
		            q.pop();
		        
		        if(q.empty())
		            ans.push_back('#');
		        else
		            ans.push_back(q.front());
		    }
		    return ans;
		}
};