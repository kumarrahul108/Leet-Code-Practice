// Leet-Code : Q.No => 1721 => Swapping Nodes in a Linked List => 22nd April


    //   



    // 1.******* Using C++ *******


    // ***** Approach - 1 ******

    int getLength(ListNode* head)
    {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            len++;
            temp =temp->next;
        }

        return len;
    }


    ListNode* swapNodes(ListNode* head, int k) 
    {
        // base 
        if(head == NULL)
        {
            return head;
        }

        int len = getLength(head);
        int start = k;
        int end = len - k + 1;  

        ListNode* ptr = head;
        int count = 0;

        while(ptr != NULL)
        {   
            count++;
            if(count == k)
            {
                ListNode* startNode = head;
                ListNode* endNode = head;
                
                // Traverse to the kth node from the start
                for (int i = 1; i < start; i++) 
                {
                    startNode = startNode->next;
                }

                // Traverse to the kth node from the end
                for (int i = 1; i < end; i++) 
                {
                    endNode = endNode->next;
                }

                // Swap values of startNode and endNode
                int temp = startNode->val;
                startNode->val = endNode->val;
                endNode->val = temp;
            }

            ptr = ptr->next;
        }
        return head;
    }



    // ***** Approach - 2 ******    

    
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* dummy = new ListNode(-1);    
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;
        ListNode* first = NULL;
        ListNode* second = NULL;

        // move fast ptr k step ahead
        for(int i=0;i<k;i++)
        {
            fast = fast->next;
        }

        // store the first node 
        first = fast;

        // move fast to end , keeping slow k step behind
        while(fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        second = slow;

        // swap values
        int temp = first->val;
        first->val = second->val;
        second->val = temp;

        return dummy->next;
    }








    // 2.******* Using Java *******

    public ListNode swapNodes(ListNode head, int k) 
    {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;

        ListNode fast = dummy;        
        ListNode slow = dummy;    

        ListNode first = null;    
        ListNode second = null;

        for (int i = 0; i < k; i++)
        {
            fast = fast.next;
        }    

        first = fast;

        while (fast != null)
        {
            fast = fast.next;
            slow = slow.next;
        }

        // Here, first and second nodes are not assigned correctly.
        // We need to adjust the slow pointer to find the second node.

        second = slow;

        // swap values
        int temp = first.val;
        first.val = second.val;
        second.val = temp;

        return dummy.next;
    }

