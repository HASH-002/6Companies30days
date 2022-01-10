class Solution {
  public:
    void preOrder(Node* root, vector<int>v[]){
        if(root){
            if(root->left){
                v[root->data].push_back(root->left->data);
                v[root->left->data].push_back(root->data);
            }
            if(root->right){
                v[root->data].push_back(root->right->data);
                v[root->right->data].push_back(root->data);
            }
            preOrder(root->left,v);
            preOrder(root->right,v);
        }
    }
    int minTime(Node* root, int target) 
    {
        vector<int> v[100000];
        bool visited[100000] = {0};
        preOrder(root, v);
        queue<int>q;
        q.push(target);
        int ans=0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                int i = q.front();
                q.pop();
                visited[i]=true;
                for(int k=0;k<v[i].size();k++)
                    if(visited[v[i][k]]==false)
                        q.push(v[i][k]);
            }
            ans++;
        }
        return ans==0 ? ans : ans-1;
    }
};