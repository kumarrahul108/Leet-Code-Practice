// Leet-Code : Q.No => 25 => Reverse Nodes in K-Group => 27th March 2024 


    //  Linked List + Recurssion + Reverse L.L


    // 1.******* Using C++ *******

    // Function to get the length of a linked list
    int getLength(ListNode* head)
    {
        ListNode* temp = head;   // Initialize a temporary pointer to the head of the list
        int len = 0;            // Initialize length counter to 0

        // Traverse the list and count the number of nodes
        while(temp != NULL)
        {
            len++;      // Increment the length counter
            temp = temp -> next;        // Move to the next node
        }

        return len; // Return the length of the list
    }

    // Function to reverse every k nodes in a linked list
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        // Base case: if the head is NULL or the next node is NULL, return the head 
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        // Initialize pointers for reversing 

        ListNode* prev = NULL;      // Pointer to the previous node
        ListNode* curr = head;      // Pointer to the current node    
        ListNode* nextNode = NULL;  // Pointer to the next node

        int pos = 0;    // Initialize position counter to 0
        int len = getLength(head);  // Get the length of the linked list
        
        // If the length of the linked list is less than k, no need to reverse, return head
        if(k > len)
        {
            return head;
        }

        // Reverse the first k nodes
        while(pos < k)
        {
            nextNode = curr->next;    // Store the next node
            curr->next = prev;    // Reverse the link
            prev = curr;         // Move prev to curr
            curr = nextNode;    // Move curr to nextNode
            pos++;           // Increment the position counter
        }

        ListNode* reccKaAns = NULL;   // Pointer to store the result of recursive call

        // If there are more nodes remaining, recursively reverse the next k nodes
        if(nextNode != NULL) 
        {
            reccKaAns = reverseKGroup(nextNode,k);   // Recursive call to reverseKGroup
            head->next = reccKaAns;         // Link the head of the current k-group to the reversed next k-group  
        }

        return prev;       // Return the new head of the reversed k-group
    }





    // 2.******* Using Java *******

    public int getLength(ListNode head)
    {
        int len = 0;
        ListNode temp = head;

        while(temp != null)
        {
            len++;
            temp = temp.next;
        }

        return len;
    }


    public ListNode reverseKGroup(ListNode head, int k) 
    {
        // base case 
        if(head == null || head.next == null)
        {
            return head;
        }

        ListNode prev = null;
        ListNode curr = head;
        ListNode nxt = null;

        int pos = 0;
        int len = getLength(head);

        if(k > len)
        {
            return head;
        } 

        while(pos < k)
        {
            nxt = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nxt;
            pos++;
        }

        ListNode reccKaAns = null;

        if(nxt != null)
        {
            reccKaAns = reverseKGroup(nxt,k);
            head.next = reccKaAns;
        }

        return prev;
    }

