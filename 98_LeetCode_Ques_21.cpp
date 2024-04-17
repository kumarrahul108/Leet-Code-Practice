// Leet-Code : Q.No => 21 => Merge two Sorted Lists => 17th April 2024 


    //  traversal in L.L + comparison to get smaller elemenst from two lists


    // 1.******* Using C++ *******


    ListNode* mergeTwoLists(ListNode* left, ListNode* right) 
    {
        // Base Case 

        // Check if left list is empty, return right list
        if(left == NULL)
        {
            return right;
        }

        // Check if right list is empty, return left list
        if(right == NULL)
        {
            return left;
        }

        // Create a dummy node to start the merged list
        ListNode* ans = new ListNode(-1);

        // Pointer to traverse the merged list
        ListNode* mptr = ans;

        // Merge the lists until either one becomes empty
        while(left != NULL && right != NULL)
        {
            // If value in left list is smaller or equal, add it to merged list
            if(left->val <= right->val)
            {
                mptr->next = left;
                mptr = left;   // Move pointer to the last added node
                left = left->next;   // Move to the next node in left list
            }

            // If value in right list is smaller, add it to merged list
            else 
            {
                mptr->next  =right;
                mptr = right;
                right = right->next;
            }
        }

        // If any nodes are left in the left list, append them to merged list
        if(left != NULL)
        {
            mptr->next = left;
        }

        // If any nodes are left in the right list, append them to merged list
        if(right != NULL)
        {
            mptr->next = right;
        }

        // Return the merged list (skipping the dummy node)
        return ans->next;   
    }






    // 2.******* Using Java *******

    public ListNode mergeTwoLists(ListNode left, ListNode right) 
    {
        // Base Case
        if(left == null)
        {
            return right;
        }    

        if(right == null)
        {
            return left;
        }

        // create dummy node 
        ListNode ans = new ListNode(-1);
        ListNode ptr = ans;

        // loop me traverse 
        while(left != null && right != null)
        {
            if(left.val <= right.val)
            {
                ptr.next = left;
                ptr = left;
                left = left.next;
            }
            else 
            {
                ptr.next = right;
                ptr = right;
                right = right.next;
            }
        }

        // if any list is left-over
        if(left != null)
        {
            ptr.next = left;
        }

        if(right != null)
        {
            ptr.next = right;
        }

        return ans.next;
    }