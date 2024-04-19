// Leet-Code : Q.No => 61 => Rotate List => 19th April 2024 


    //  length of list + 2 pointer



    // 1.******* Using C++ *******


    // Function to calculate the length of a linked list
    int getLength(ListNode* head)
    {
        // Initialize length counter
        int len = 0;
        ListNode* ptr = head;   // Pointer to traverse the list

        // Traverse the list and count the number of nodes
        while(ptr != NULL)
        {
            len++;    // Increment length
            ptr = ptr->next;   // Move to the next node
        }

        // Return the length of the list
        return len;
    } 


    // Function to rotate a linked list to the right by k positions
    ListNode* rotateRight(ListNode* head, int k) 
    {
        // Base case: If the list is empty, return NULL 
        if(head == NULL)
        {
            return NULL;
        }

        // Get the length of the list
        int len = getLength(head);

        // Calculate the actual number of positions to rotate
        int actualRotateK = (k % len);

        // If the actual number of positions to rotate is 0, no rotation needed, return the original list
        if(actualRotateK == 0)
        {
            return head;
        }

        // Calculate the new position of the last node after rotation
        int newPos = len - actualRotateK -1;
        ListNode* newLastNode = head;

        // Traverse to the new position of the last node
        for(int i=0;i<newPos;i++)
        {
            newLastNode = newLastNode->next;
        }

        // The node after the new last node becomes the new head of the rotated list
        ListNode* newHead = newLastNode->next; 
        newLastNode->next = NULL;   // Disconnect the new last node from the rest of the list

        // Traverse to the end of the rotated list to find the current last node    
        ListNode* itr = newHead;
        while(itr->next != NULL)
        {
            itr = itr->next;
        }

        // Connect the current last node to the original head of the list to complete the rotation
        itr->next = head;

        // Return the new head of the rotated list
        return newHead;
    }








    // 2.******* Using Java *******


    class Solution {
    public int getLength(ListNode head)
    {
        int len = 0;
        ListNode ptr = head;

        while(ptr != null)
        {
            len++;
            ptr = ptr.next;
        }

        return len;
    }


    public ListNode rotateRight(ListNode head, int k) 
    {
        // base case 
        if(head == null)
        {
            return null;
        }         

        int len = getLength(head);
        int actualRotateK = (k % len);

        if(actualRotateK == 0)
        {
            return head;
        }

        int newPos = len - actualRotateK - 1;
        ListNode newLastNode = head;

        for(int i=0;i < newPos;i++)
        {
            newLastNode = newLastNode.next;
        }

        ListNode newHead = newLastNode.next;
        newLastNode.next = null;

        ListNode itr = newHead;

        while(itr.next != null) 
        {
            itr = itr.next;
        }

        itr.next = head;

        return newHead;
    }
}    

