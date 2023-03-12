class Solution
{
public:
    struct compare
    {
        bool operator()(ListNode *x, ListNode *y)
        {
            return x->val > y->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        ListNode *newHead = new ListNode(0);
        ListNode *tail = newHead;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != NULL)
            {
                q.push(lists[i]);
            }
        }
        while (!q.empty())
        {
            ListNode *temp = q.top();
            tail->next = temp;
            tail = temp;
            q.pop();
            if (temp->next != NULL)
            {
                q.push(temp->next);
            }
        }
        return newHead->next;
    }
};