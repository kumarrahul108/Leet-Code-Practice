// Leet-Code : Q.No => 2816 => Double a Number Represented as a Linked List => 21st April 2024 


    //  list traversal + carry - sum + recurssion 



    // 1.******* Using C++ *******


    // Recursive function to double the value of each node in the linked list
    // and handle any carry generated during the process
    void solve(ListNode* head, int &carry)
    {
        // Base case: if head is NULL, return
        if (!head) 
        {
            return;
        }

        // Recursively call solve on the next node
        solve(head->next, carry);

        // Now we have reached the last node
        // Handle the case for the last node
        int prod = (head->val * 2) + carry; // Calculate the product of current node's value and 2, and add carry
        head->val = prod % 10;  // Update the current node's value with the last digit of the product
        carry = prod / 10;  // Update carry for the next node
    }

    // Function to double the value of each node in the linked list
    // and return the head of the modified list
    ListNode* doubleIt(ListNode* head) 
    {
        int carry = 0;  // Initialize carry to 0
        solve(head, carry);  // Call the solve function to double the values of nodes

        // If carry is generated after processing all nodes
        if (carry) 
        {
            // Create a new node for the carry
            ListNode* carryNode = new ListNode(carry);
            carryNode->next = head;  // Attach the current list after the carry node
            head = carryNode;  // Update head to the carry node
        }

        return head;  // Return the head of the modified list
    }






    // 2.******* Using Java *******

    public void solve(ListNode head, int[] carry)
    {
        // base case 
        if (head == null)
        {
            return;
        }

        solve(head.next, carry);

        // 1-case solve
        int prod = (head.val * 2) + carry[0];
        head.val = prod % 10;
        carry[0] = prod / 10; 
    }

    public ListNode doubleIt(ListNode head) 
    {
        int[] carry = new int[1]; // Array to hold carry value
        carry[0] = 0; // Initialize carry
        solve(head, carry); // Pass carry by reference using array

        if (carry[0] != 0)
        {
            ListNode carryNode = new ListNode(carry[0]);
            carryNode.next = head;
            head = carryNode;
        }

        return head;
    }

