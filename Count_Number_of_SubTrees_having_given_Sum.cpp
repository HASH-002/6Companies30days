int solve(Node* r, int x, int&ans){
    if(!r)
        return 0;
    
    int lsum = solve(r->left,x,ans);
    int rsum = solve(r->right,x,ans);
    int sum = r->data + lsum + rsum;
    if(sum == x)
        ans++;
    return sum;    
}
int countSubtreesWithSumX(Node* r, int x)
{
	int ans =0;
	solve(r,x,ans);
	return ans;
}