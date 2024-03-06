
// Leet-Code : Q.No => 141 => Linked List Cycle -> 6th March 2024 


    // 1. Using C++

    bool hasCycle(ListNode *head) 
    {
        ListNode* slow = head;  
        ListNode* fast = head;

        while(fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }

            // loop check 
            if(fast == slow)
            {
                return true;
            }
        }  
        return false;
    }



    // 2. Using Java 

    public boolean hasCycle(ListNode head) 
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

            if(slow == fast)
            {
                return true;
            }
        } 
        return false;   
    }
