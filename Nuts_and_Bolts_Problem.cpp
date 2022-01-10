class Solution{
public:	
	void matchPairs(char nuts[], char bolts[], int n) {
	    unordered_set<char>s;
	    for(int i=0;i<n;i++)
	        s.insert(nuts[i]);
	    
	    int j=0;
	    char a[9] = {'!','#','$','%','&','*','@','^','~'};
	    for(int i=0;i<9;i++){
	        if(s.find(a[i])!=s.end())
	            nuts[j++]=a[i];
	    }
	    
	    for(int i=0;i<n;i++)
	        bolts[i] = nuts[i];
	}
};