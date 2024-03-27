// Leet-Code : Q.No => 83 => Remove Duplicates from Sorted List => 27th March 2024 


    //  Linked List + 2-pointer + comparison 


    // 1.******* Using C++ *******

    ListNode* deleteDuplicates(ListNode* head) 
    {
        // Base case: if the head is NULL or the next node is NULL, return the head
        if(head == NULL || head->next == NULL)
        {
            return head;
        }    

        // Initialize a pointer 'curr' to traverse the list starting from the head
        ListNode* curr = head;

        // Traverse the list
        while(curr != NULL)
        {
            // Check if the current node has a duplicate next node
            if((curr->next != NULL) && (curr->val == curr->next->val))
            {
                // If a duplicate is found, remove the next node
                ListNode* repeat = curr->next;
                curr->next = repeat->next;
                repeat->next = NULL;     // Remove the link from the list
                delete repeat;    // Delete the duplicate node from memory
            }
            else 
            {
                // If no duplicate is found, move to the next node
                curr = curr->next;
            }  
        }

        // Return the head of the modified list
        return head;
    }




    // 2.******* Using Java *******

    public ListNode deleteDuplicates(ListNode head) 
    {
        // base case 
        if(head == null || head.next == null)
        {
            return head;
        }    

        ListNode curr = head;

        while(curr != null)
        {
            if((curr.next != null) && (curr.val == curr.next.val))
            {
                ListNode repeat = curr.next;
                curr.next = repeat.next;
                repeat.next = null;
            }
            else 
            {
                curr = curr.next;
            }
        }

        return head;
    }   