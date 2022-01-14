vector<string> generate(int n)
{
	vector<string>v;
	queue<string>q;
	q.push("1");
    while(n--){
        string s = q.front();
        q.pop();
        v.push_back(s);
        q.push(s+"0");
        q.push(s+"1");
    }
	return v;
}