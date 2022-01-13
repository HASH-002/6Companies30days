class Solution
{
    public:
    Node* getNextNode(Node *q){
        Node* temp = q->nextRight;
        while(temp){
            if(temp->left)
                return temp->left;
            if(temp->right)
                return temp->right;
            temp = temp->nextRight;
        }
        return temp;
    }
    void connect(Node *root)
    {
        Node *p = root;
        p->nextRight = NULL;
        while(p){
            Node *q = p;
            while(q){
                if(q->left){
                    if(q->right)
                        q->left->nextRight = q->right;
                    else
                        q->left->nextRight = getNextNode(q);
                }
                if(q->right)
                    q->right->nextRight = getNextNode(q);
                q = q->nextRight;
            }
            if(p->left)
                p = p->left;
            else if(p->right)
                p = p->right;
            else
                p = p->nextRight;
        }
    }    
};