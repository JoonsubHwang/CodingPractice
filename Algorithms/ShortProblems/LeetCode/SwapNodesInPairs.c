/*
    Recursion
    https://leetcode.com/explore/learn/card/recursion-i/250/principle-of-recursion/1681/
    
    
    Swap linked list nodes in pairs
    
    Input: ListNode*
    Change from 1->2->3->4 to 2->1->4->3
*/

typedef struct ListNode 
{
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;

ListNode* swapPairs(ListNode* head) 
{
    // if head == nullptr, return nullptr OR if 2nd node doesn't exist, return head
    ListNode* returnNode = head; 

    if (head != nullptr) // if head -- nulptr, don't try to access second node
    {
        if (head->next != nullptr) // if second node exists, swap first and second
        {
            ListNode* second = head->next;
            head->next = second->next; // 1->3
            second->next = head; // 2->1
            returnNode = second;

            if (head->next != nullptr) // if third node exists, swapPairs(third)
                head->next = swapPairs(head->next); // 1->4->3 ...  OR 1->3
        }
    }

    return returnNode;
}

/*
This should work as well but needs testing
(may run for too long for some reason)

ListNode* swapPairs(ListNode* head) 
{
    // if head == nullptr, return nullptr OR if 2nd node doesn't exist, return head
    ListNode* returnNode = head; 

    if (head != nullptr) // if head -- nulptr, don't try to access second node
    {
        if (head->next != nullptr) // if 2nd node exists, swap 1st and 2nd
        {
            returnNode = head->next; // return 2nd node
            ListNode* third = returnNode->next; // store 3rd node
            returnNode->next = head; // 2->1

            if (third != nullptr) // if third node exists, swapPairs(theRestOfList)
                head->next = swapPairs(third); // 1->4->3 ... OR 1->3
        }
    }

    return returnNode;
}
*/
