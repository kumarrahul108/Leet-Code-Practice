// Leet-Code : Q.No => 2487 => Remove Nodes From Linked List => 6th May


    //  linked list + stacks 


    // 1.******* Using Java ******* 


    public ListNode removeNodes(ListNode head) 
    {
        // Create a stack to store the nodes in non-decreasing order
        Stack<ListNode> st = new Stack<>();
        ListNode curr = head;

        // Traverse the linked list
        while(curr != null)
        {
            // Remove nodes from the stack which have values less than the current node's value
            while(!st.isEmpty() && st.peek().val < curr.val)
            {
                st.pop();
            }

            // Push the current node onto the stack
            st.push(curr);

            // Move to the next node
            curr = curr.next;
        }  

        // Create a dummy node to build the resulting linked list    
        ListNode dummy= new ListNode(0);
        ListNode prev = dummy;

        // Iterate through the stack to construct the new linked list in non-decreasing order
        for(ListNode node : st)
        {
            prev.next = node;
            prev = prev.next;
        }      

        // Set the next pointer of the last node to null to terminate the list
        prev.next = null;

        // Return the head of the new linked list
        return dummy.next;
    }
