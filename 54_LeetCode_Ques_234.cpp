// Leet-Code : Q.No => 234 => Pallindrome Linked List  => 21st March 2024 


    //  (middle + reverse) of Linked List  +  comparison 


    // 1.******* Using C++ *******

    public:
    ListNode* middle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL)
        {
            fast = fast->next;
            if(fast->next != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }

        return slow;
    }

    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL)
        {
            ListNode* nxt = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nxt;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) 
    {
        // base case 
        if(head == NULL || head->next == NULL)
        {
            return true;
        }

        // find middle elelment of L.L 
        ListNode* mid = middle(head); 

        // reverse element after mid + 1 
        ListNode* rev = reverse(mid->next);

        // comparison   
        while(head != NULL && rev != NULL)
        {
            if(head->val == rev->val)
            {
                head = head->next;
                rev = rev->next; 
            }
            else 
            {
                return false;
            }
        }    

        return true;
    }





    // ******* Using Java  **********

    public ListNode middle(ListNode head)
    {
        ListNode slow = head;
        ListNode fast = head;

        while(fast.next != null && fast.next.next != null)
        {
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }


    public ListNode reverse(ListNode head)
    {
        ListNode prev = null;
        ListNode curr = head;

        while(curr != null)
        {
            ListNode nxt = curr.next;
            curr.next = prev;

            prev = curr;
            curr = nxt;
        }
        return prev;
    }


    public boolean isPalindrome(ListNode head) 
    {
        // base 
        if(head == null || head.next == null)
        {
            return true;
        }    

        // middle element of L.L
        ListNode mid = middle(head);

        // revere mid + 1 
        ListNode newlist = reverse(mid.next);

        // comparison 
        while(head != null && newlist != null)
        {
            if(head.val == newlist.val)
            {
                head = head.next;
                newlist = newlist.next;
            }
            else 
            {
                return false;
            }
        }

        return true;
    }