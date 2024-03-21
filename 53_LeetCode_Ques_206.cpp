// Leet-Code : Q.No => 206 => Reverse Linked List  => 21st March 2024 


    // 


    // 1.******* Using C++ *******


    // ***** Approach - 1 *********
    ListNode* reverseList(ListNode* head) 
    {
        // base 
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode* prev = head;
        ListNode* curr = head->next; 

        while(curr != NULL)
        {
            ListNode* nxt = curr->next;
            curr->next = prev;

            // upadte ptr 
            prev = curr;
            curr = nxt;
        }   

        head->next = NULL;
        return prev;
    }



    // ***** Approach - 2 *********

    ListNode* reverseList(ListNode* head) 
    {   
        // Base case: If the list is empty or has only one node, it's already reversed
        if(head == NULL || head->next == NULL)
        {
            return head;    // Return the head of the list
        }

        // Initialize pointers to keep track of the previous and current nodes
        ListNode* prev = NULL;    // Initially, there is no previous node
        ListNode* curr = head;    // Start from the head of the list

        // Traverse the list and reverse the direction of pointers
        while(curr != NULL)
        {
            // Store the next node temporarily
            ListNode* nxt = curr->next;

            // Reverse the direction of the pointer
            curr->next = prev;

            // Update pointers for the next iteration
            prev = curr;
            curr = nxt;
        }

        return prev;   // After the loop, 'prev' will point to the new head of the reversed list
    }



    // ***** Approach - 3 *********

    ListNode* reverseRecc(ListNode* prev,ListNode* curr)
    {
        // Base case: If 'curr' reaches the end of the list (NULL), return 'prev' 
        if(curr == NULL)
        {
            return prev;
        }

        // Store the next node temporarily
        ListNode* nxt = curr->next;

        // Reverse the direction of the pointer
        curr->next = prev;

        // Update pointers for the next iteration
        prev = curr;
        curr = nxt;  

        // Recurssively call the function with updated pointers
        ListNode* rev = reverseRecc(prev,curr);

        return rev;  // Return the head of the reversed list
    }

    ListNode* reverseList(ListNode* head) 
    {
        // base 
        if(head == NULL || head->next == NULL)
        {
            return head;    
        }
        
        // Initialize pointers to keep track of the previous and current nodes
        ListNode* prev = NULL;
        ListNode* curr = head;

        // Call the helper function to reverse the list recursively
        ListNode* newHead = reverseRecc(prev,curr);

        return newHead;   // Return the new head of the reversed list   
    }









    // ************** Using Java ************ 

    // ****** Approach - 1 ************

    public ListNode reverseList(ListNode head) 
    {
        // base 
        if(head == null || head.next == null)
        {
            return head;
        }    

        ListNode prev = null;
        ListNode curr = head;

        while(curr != null)
        {
            ListNode nxt = curr.next;
            curr.next = prev;

            // update
            prev = curr;
            curr = nxt;
        }

        return prev;
    }



    // ******* Approach - 2 **********

    public ListNode reverseList(ListNode head) 
    {
        if(head == null || head.next == null)
        {
            return head;
        }    

        ListNode newHead = reverseList(head.next);
        head.next.next = head;
        head.next = null;

        return newHead;
    }
