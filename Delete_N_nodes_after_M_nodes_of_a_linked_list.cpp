class Solution
{
    public:
    void linkdelete(struct Node  *head, int m, int n)
    {
        while(head){
            Node*prev=head;
            for(int i=0;head && i<m;i++){
                prev = head;
                head = head->next;
            }
            for(int i=0;head && i<n;i++)
                head = head->next;
            prev->next = head;
        }
    }
};