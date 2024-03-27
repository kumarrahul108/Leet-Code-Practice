// Leet-Code : Q.No => 142 => Linked List Cycle II => 27th March 2024 


    //  Linked List + 2 Pointer (slow + fast) 


    // 1.******* Using C++ *******

    ListNode *detectCycle(ListNode *head) 
    {
        // Base case: if the head is NULL or the head's next node is NULL, there is no cycle
        if(head == NULL || head->next == NULL)
        {
            return NULL;
        }  

        // Initialize two pointers, slow and fast, both starting from the head of the list
        ListNode* slow = head;      
        ListNode* fast = head;
        bool meet = 0;

        
        // Traverse the list using the slow and fast pointers
        while(fast != NULL)
        {
            // Move the fast pointer two steps ahead
            fast = fast->next;
            if(fast != NULL)
            {
                fast = fast->next;   // Move fast pointer two steps again
                slow = slow->next;   // Move slow pointer one step
            }

            // If fast and slow pointers meet, it indicates the presence of a cycle
            if(fast == slow)
            {
                meet = 1;
                break;    // Exit the loop
            }
        }  

        // if cycle present     
        if(meet == 1)
        {
            // Reset the slow pointer to the head of the list
            slow = head;

            // Move both slow and fast pointers at the same pace until they meet
            while(fast != slow)
            {
                fast = fast->next;
                slow = slow->next;    
            }

            // Return the node where the two pointers meet, indicating the start of the cycle
            return slow;
        }

        return NULL;  
    }






    // 2.******* Using Java *******

    public ListNode detectCycle(ListNode head) 
    {
        // base 
        if(head == null || head.next == null)
        {
            return null;
        }

        ListNode slow = head;                
        ListNode fast = head;   
        boolean meet = false;             

        while(fast != null)
        {
            fast = fast.next;
            if(fast != null)
            {
                fast = fast.next;
                slow = slow.next;
            }

            if(fast == slow)
            {
                meet = true;
                break;
            }
        }

        if(meet == true)
        {
            slow = head;

            while(slow != fast)
            {
                slow = slow.next;
                fast = fast.next;
            }

            return slow;
        }  

        return null;              
    }
}