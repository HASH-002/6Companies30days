class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    ull  i=0;
	    set<ull>s;
	    s.insert(1);
	    ull num1=2, num2=3, num3=5;
	    while(i<n){
	        i++;
	        ull num = *s.begin();
	        s.erase(s.begin());
	        if(i==n)
	            return num;
	        else{
	            s.insert(num*2);
	            s.insert(num*3);
	            s.insert(num*5);
	        }
	    }
	    return 0;
	}
};