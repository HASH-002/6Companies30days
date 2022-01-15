class Solution{
    public:
    string findOrder(string a[], int n, int k) {
        unordered_map<char,int>in;
        map<char,vector<char>>g;
        int i=1;
        while(i<n){
            int j=0;
            while(j<a[i-1].length() && j<a[i].length() && a[i-1][j]==a[i][j])
                j++;
            if(j<a[i-1].length() && j<a[i].length()){
                g[a[i-1][j]].push_back(a[i][j]);
                in[a[i-1][j]]=0;
                in[a[i][j]]=0;
            }
            i++;
        }
        
        for(auto i=g.begin();i!=g.end();i++)
	        for(int j=0;j<g[i->first].size();j++)
	            in[g[i->first][j]]++;
	            
	    queue<char>q;
	    for(auto i=in.begin();i!=in.end();i++)
	        if(!in[i->first])
	            q.push(i->first);
	    
	    string s;
	    while(!q.empty()){
	        char p = q.front();
	        q.pop();
	        in[p]=-1;
	        s.push_back(p);
	        for(int i=0;i<g[p].size();i++){
	            in[g[p][i]]--;
	            if(!in[g[p][i]])
	                q.push(g[p][i]);
	        }
	    }
	    return s;
    }
};