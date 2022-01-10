class Solution
{
    public:
    void serializeHelper(Node *root, vector<int>&v)
    {
        if(root == NULL)
            v.push_back(-1);
        else{
            v.push_back(root->data);
            serializeHelper(root->left, v);
            serializeHelper(root->right, v);
        }
    }
    vector<int> serialize(Node *root) 
    {
        vector<int>v;
        serializeHelper(root,v);
        return v;
    }
    
    Node* deSerializeHelper(vector<int>&v, int& i)
    {
        if(i == v.size())
            return NULL;
        
        int data = v[i++];
        if(data == -1)
            return NULL;
        
        Node* root = new Node(data);
        root->left = deSerializeHelper(v,i);
        root->right = deSerializeHelper(v,i);
        return root;
    }
    Node * deSerialize(vector<int> &v)
    {
        int index=0; 
        Node *root = deSerializeHelper(v,index);
        return root;
    }

};