// Leet-Code : Q.No => 138 => Copy List with Random Pointer => 20th April 2024 


    //  list traversal + hash table (mapping) 



    // 1.******* Using C++ *******  


    Node* helper(Node* head,unordered_map<Node*,Node*> &mp)
    {
        // base case 
        if(head == NULL)
        {
            return NULL;
        }

        Node* newHead = new Node(head->val);
        mp[head] = newHead;
        newHead->next = helper(head->next,mp);

        if(head->random)
        {
            newHead->random = mp[head->random];
        }

        return newHead;
    }

    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node* , Node* > mp;

        return helper(head,mp);    
    }
