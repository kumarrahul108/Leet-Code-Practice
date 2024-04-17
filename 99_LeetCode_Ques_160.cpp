// Leet-Code : Q.No => 160 => Intersection of Two Linked List => 17th April 2024 


    //  traversal in L.L + comparison to get smaller elemenst from two lists


    // 1.******* Using C++ *******

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        // Create temporary pointers to traverse the lists
        ListNode* a = headA;    
        ListNode* b = headB;  

        // Traverse both lists until either one reaches the end
        while(a->next && b->next)  // a->next != NULL
        {
            // If the current nodes in both lists are the same, it's the intersection point
            if(a == b)
            {
                return a;
            }

            // Move to the next nodes in both lists
            a = a->next;
            b = b->next;
        }   

        // If list A reaches its end first
        if(a->next == NULL)
        {
            int blen = 0;
            // Calculate the length of list B
            while(b->next)
            {
                blen++;
                b = b->next;
            }

            // Move list B's head pointer forward by the difference in lengths
            while(blen--)
            {
                headB = headB->next;
            }
        }
        // If list B reaches its end first
        else
        {
            int alen = 0;
            // Calculate the length of list A
            while(a->next)
            {
                alen++;
                a = a->next; 
            }

            // Move list A's head pointer forward by the difference in lengths
            while(alen--)
            {
                headA = headA->next;        
            }
        }

        // Move both list pointers until they meet at the intersection node
        while(headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }

        // Return the intersection node (or NULL if there's no intersection)
        return headA;
    }






    // 2.******* Using Java *******


    // ***** approach - 1 *******

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) 
    {
        // temporary ptr 
        ListNode a = headA;    
        ListNode b = headB;   

        // traverse 
        while(a.next != null && b.next != null)
        {
            if(a == b)
            {
                return a;
            }

            a = a.next;
            b = b.next;
        } 

        // if a < b 
        if(a.next == null)
        {
            int blen = 0;
            while(b.next != null)
            {
                blen++;
                b = b.next;
            }

            while(blen != 0)
            {
                headB = headB.next;
                blen--;
            }
        }
        else 
        {
            int alen = 0;
            while(a.next != null)
            {
                alen++;
                a = a.next;
            }

            while(alen != 0)
            {
                headA = headA.next;
                alen--;
            }
        }

        // comparison
        while(headA != headB)
        {
            headA = headA.next;
            headB = headB.next;
        } 

        return headA;
    }




    // ***** approach - 2 ***** 

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) 
    {
        // create temp pointer 
        ListNode a = headA;    
        ListNode b = headB;    

        int alen = 0;
        int blen = 0;

        // len of A
        while(a != null)
        {
            a = a.next;
            alen++;
        }

        // len of B
        while(b != null)
        {
            b = b.next;
            blen++;
        }

        // len a > len b
        if(alen > blen)
        {
            int diff = alen - blen;
            while(diff != 0)
            {
                headA = headA.next;
                diff--;
            }
        }
        // len a < len b
        else if(blen > alen)
        {
            int diff = blen - alen;
            while(diff != 0)
            {
                headB = headB.next;
                diff--;
            }
        }

 
        // comparison 
        while(headA != null)
        {
            if(headA == headB)
            {
                return headA;
            }

            headA = headA.next;
            headB = headB.next;
        }

        return null;
    }
