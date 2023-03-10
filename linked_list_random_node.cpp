class Solution
{
    int count = 0;
    ListNode *newHead;

public:
    Solution(ListNode *head)
    {

        newHead = head;
        ListNode *current = newHead;
        while (current != NULL)
        {
            count++;
            current = current->next;
        }
    }

    int getRandom()
    {
        int randIdx = rand() % count;
        ListNode *current = newHead;
        for (int i = 0; i < randIdx; i++)
        {
            current = current->next;
        }
        return current->val;
    }
};