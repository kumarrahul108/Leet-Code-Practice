// Leet-Code : Q.No => 148 => Sort List => 18th April 2024 


    //  Merge SOrt Sorting + 2 list ko sort wali technique



    // 1.******* Using C++ *******

    // Function to find the middle node of a linked list
    ListNode* findMid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        // Move slow pointer by one step and fast pointer by two steps
        while(fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        // At this point, slow pointer points to the middle node
        return slow;
    }

    // Function to merge two sorted linked lists
    ListNode* merge(ListNode* left,ListNode* right)
    {
        // Base cases
        if(left == NULL)
        {
            return right;
        }

        if(right == NULL)
        {
            return left;
        }

        // Initialize a dummy node to start the merged list
        ListNode* ans = new ListNode(-1);
        ListNode* ptr = ans;

        // Merge the lists until either one becomes empty
        while(left && right)
        {
            // Compare values of nodes in both lists
            if(left->val <= right->val)
            {
                ptr->next= left;
                ptr = left;
                left = left->next;
            }
            else 
            {
                ptr->next = right;
                ptr = right;
                right = right->next;
            }
        }

        // If any nodes are left in the left list, append them to the merged list
        if(left != NULL)
        {
            ptr->next = left;
        }

        // If any nodes are left in the right list, append them to the merged list
        if(right != NULL)
        {
            ptr->next = right;
        }

        // Return the merged list (skipping the dummy node)
        return ans->next;
    }

    // Function to sort a linked list using merge sort
    ListNode* sortList(ListNode* head) 
    {
        // Base case: If the list is empty or has only one node, it is already sorted
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        // Find the middle node of the list
        ListNode* mid = findMid(head);

        // Split the list into two halves
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        // Recursively sort both halves
        left = sortList(left);
        right = sortList(right);

        // Merge the sorted halves
        ListNode* mergeLL = merge(left,right);

        // Return the sorted list
        return mergeLL;
    }








    // 2.******* Using Java *******

    public ListNode findMid(ListNode head)
    {
        ListNode slow = head;
        ListNode fast = head;

        while(fast.next != null && fast.next.next != null)
        {
            slow = slow.next;
            fast = fast.next.next; 
        }

        return slow;
    }

    public ListNode merge(ListNode left,ListNode right)
    {
        // base 
        if(left == null)
        {
            return right;
        }

        if(right == null)
        {
            return left;
        }

        ListNode ans = new ListNode(-1);
        ListNode ptr = ans;

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

        // leftover elements
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

    public ListNode sortList(ListNode head) 
    {
        // base 
        if(head == null || head.next == null)
        {
            return head;
        }

        // mid calculate
        ListNode mid = findMid(head);

        ListNode left = head;
        ListNode right = mid.next;
        mid.next = null;

        left = sortList(left);
        right = sortList(right);

        // sort 
        ListNode mergeLL = merge(left,right);

        return mergeLL;
    }




