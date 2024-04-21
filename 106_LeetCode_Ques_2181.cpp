// Leet-Code : Q.No => 2181 => Merge Nodes in Between Zeros => 21st April 2024 


    //  list traversal + 2 pointer appeoach  



    // 1.******* Using C++ *******


    ListNode* mergeNodes(ListNode* head) 
    {
        // Base case: if the head is NULL, return NULL
        // if(head == NULL)
        // {
        //     return NULL;
        // }        

        // Alternatively, if head is NULL, return head
        if(!head)
        {
            return head;
        }

        // Initialize pointers for traversal
        ListNode* slow = head;  // Slow pointer starts at head
        ListNode* fast = head->next;  // Fast pointer starts at the node next to head
        ListNode* ptr = head;  // Pointer to keep track of the last node with non-zero value
        int sum = 0;  // Variable to accumulate the sum of non-zero values

        // Traverse the list until fast pointer reaches the end
        // while(fast != NULL)
        while(fast)
        {
            // If the value of the current node pointed by fast is not zero
            if(fast->val != 0)
            {
                // Accumulate its value to sum
                sum += fast->val;
            }
            // If the value is zero
            else 
            {
                // Update the value of the node pointed by slow to the sum
                slow->val = sum;
                // Move ptr to the current slow position
                ptr = slow;
                // Move slow to the next node
                slow = slow->next;
                // Reset sum to zero
                sum = 0;        
            }
            // Move fast pointer to the next node
            fast = fast->next;
        }

        // After traversal, cut off the remaining nodes starting from ptr->next
        ListNode* temp = ptr->next;
        ptr->next = NULL;

        // Delete the remaining nodes
        while(temp)
        {
            ListNode* nxt = temp->next;  // Store the next node
            delete temp;  // Delete the current node
            temp = nxt;  // Move temp to the next node
        }

        // Return the modified head of the list
        return head;
    }








    // 2.******* Using Java *******


    public ListNode mergeNodes(ListNode head) 
    {
        // base case 
        if(head == null)
        {
            return head;
        }    

        // initialise pointers 
        ListNode slow = head;
        ListNode fast = head.next;
        ListNode ptr = head;
        int sum = 0;

        // loop -> uptill fast ptr
        while(fast != null)
        {
            if(fast.val != 0)
            {
                sum += fast.val;
            }
            else 
            {
                slow.val = sum;
                ptr = slow;
                slow = slow.next;
                sum = 0;
            }
            fast = fast.next;
        }

        // relinking our nodes
        ListNode temp = ptr.next;
        ptr.next = null;

        return head;
    }
