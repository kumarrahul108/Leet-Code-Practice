// Leet-Code : Q.No => 876 => Middle of the Linked List -> 7th March 2024 

    // slow - fast pointer approach


    // 1. Using C++

    ListNode* middleNode(ListNode* head) 
    {
        // Initialize two pointers: slow and fast, both pointing to the head of the list
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse the list using the fast pointer
        while(fast != NULL)
        {
            // Move the fast pointer two steps ahead
            fast = fast->next;
            
            // Check if fast pointer has reached the end of the list        
            if(fast != NULL)
            {
                // If fast pointer has not reached the end, move it one more step ahead
                fast = fast->next;

                // Move the slow pointer one step ahead
                slow = slow->next;
            }
        }

        // When the fast pointer reaches the end of the list, the slow pointer will be at the middle
        return slow;
    }



    // 2. Using Java 

    public ListNode middleNode(ListNode head) 
    {
        ListNode slow = head;    
        ListNode fast = head;

        while(fast != null)
        {
            fast = fast.next;
            if(fast != null)
            {
                fast = fast.next;
                slow = slow.next;
            }
        }    
        return slow;
    }
