// Leet-Code : Q.No => 328 => Odd Even Linked List => 20th April 2024 


    //  list traversal + 2 pointer approach 



    // 1.******* Using C++ *******

    class Solution {
    public:
    ListNode* oddEvenList(ListNode* head) 
    {
        // Check if the list is empty or has only one node
        if(head == NULL || head->next == NULL)
        {
            return head;
        } 

        // Initialize pointers for odd and even nodes
        ListNode* odd = head;
        ListNode* even = head->next;
        // Save the start of even nodes to link them later
        ListNode* evenStart = head->next;

        // Iterate until either even or even->next becomes NULL
        while(even != NULL && even->next != NULL)
        {
            // for odd nodes

            // Connect odd nodes
            odd->next = even->next;
            // Move odd pointer to the next odd node
            odd = odd->next;

            // for even nodes
            
            // Connect even nodes
            even->next = odd->next;
            // Move even pointer to the next even node
            even = even->next;
        }  

        // link the last odd node to the first even node
        odd->next = evenStart;

        // Return the modified list
        return head;
    }
};








    // 2.******* Using Java *******

    class Solution {
    public :
    ListNode oddEvenList(ListNode head) 
    {
        // base case 
        if(head == null || head.next == null)
        {
            return head;
        }    

        ListNode odd = head;
        ListNode even = head.next;
        ListNode evenStart = head.next;

        while(even != null && even.next != null)
        {
            // odd 
            odd.next = even.next;
            odd = odd.next;

            // even 
            even.next = odd.next;
            even = even.next;
        }

        // link 
        odd.next = evenStart;

        return head;
    }
}