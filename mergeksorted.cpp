/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   struct compare
{
	bool operator()(
		struct ListNode* a, struct ListNode* b)
	{
		return a->val> b->val;
	}
};
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
    priority_queue<ListNode*,vector<ListNode*>,compare> pq;

        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=NULL)
            pq.push(lists[i]);
        }
        ListNode *curr=new ListNode(0);
         ListNode* start=curr;
        while(!pq.empty())
        {
            ListNode* nt=pq.top();
            pq.pop();
            curr->next=nt;
            curr=nt;
            if(curr->next)
                pq.push(curr->next);
        }
        return start->next;
    }
};
