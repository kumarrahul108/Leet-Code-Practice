// Leet-Code : Q.No => 237 => Delete Node in a Linked List => 5th May


    //  linked list traversal   



    // 1.******* Using C++ ******* 


    // *** approach - 1 *** 

    void deleteNode(ListNode* node) 
    {
         // Copy the value of the next node to the current node
        node->val = node->next->val;

        // Point the current node's next pointer to the next node's next pointer
        node->next = node->next->next;
    }


    // *** approach - 2 *** 

     void deleteNode(ListNode* node) 
    {
        // Copy the value of the next node to the current node
        ListNode* nextNode = node->next;
        node->val = nextNode->val;

        // Point the current node's next pointer to the node after the next node
        node->next = nextNode->next;

        // Delete the next node to effectively remove it from the linked list
        delete nextNode;       
    }    





    // 2.******* Using Java ******* 


    public void deleteNode(ListNode node) 
    {
        ListNode nextNode = node.next;
        node.val = nextNode.val;
        node.next = nextNode.next;      
    } 
