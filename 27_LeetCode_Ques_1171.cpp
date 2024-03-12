// Leet-Code : Q.No => 1171 => Remove Zero Sum Consecutive Nodes from Linked List -> 12th March 2024 


    //  map concept & linked list


    // 1. Using C++


    // Function to sanitize the map based on the cumulative sum
    void sanitizeMap(ListNode* head,unordered_map<int,ListNode*> &mp,int csum)
    {   
        int temp = csum;    
        // Iterate through the linked list
        while(true)
        {
            // Update the cumulative sum
            temp = temp + head->val;

            // If the cumulative sum becomes equal to the original sum, break the loop
            if(temp == csum)
            {
                break;
            }

            // Otherwise, erase elements from the map corresponding to the updated cumulative sum
            mp.erase(temp);

            // Move to the next node in the linked list
            head = head->next;
        }
    }

    ListNode* removeZeroSumSublists(ListNode* head) 
    {
        // base case : If the head is null or if there's only one node with value 0, return null
        if(!head || (!head->next && head->val == 0))
        {
            return NULL;
        }

        // Initialize an unordered map to store cumulative sums and corresponding nodes
        unordered_map<int,ListNode*> mp;
        auto it = head;   // Initialize an iterator to traverse the linked list
        int csum = 0;  // Initialize the cumulative sum

        // Iterate through the linked list
        while(it)
        {
            // Update the cumulative sum
            csum = csum + it->val;

            // If the cumulative sum becomes zero, remove all elements in the sublist from the map
            if(csum == 0)
            {
                head = it->next;
                mp.clear();
            }

            // If the cumulative sum is found in the map, sanitize the map and update the linked list
            else if(mp.find(csum) != mp.end())
            {
                sanitizeMap(mp[csum]->next,mp,csum);
                mp[csum]->next = it->next;
            }

            // If the cumulative sum is encountered for the first time, add it to the map along with the corresponding node
            else  
            {
                mp[csum] = it;
            }
            it = it->next;  // Move to the next node in the linked list
        }
        return head;    // Return the modified head of the linked list
    }




    // 2. Using Java 

    public void sanitizeMap(ListNode head,HashMap<Integer,ListNode> mp,int csum)
    {
        int temp = csum;

        while(true)
        {
            temp += head.val;

            if(temp == csum)
            {
                break;
            }

            mp.remove(temp);
            head = head.next;
        }
    }

    public ListNode removeZeroSumSublists(ListNode head) 
    {
        // base case 
        if(head == null || head.next == null && head.val == 0)
        {
            return null;
        }

        int csum = 0;           
        ListNode itr = head;
        HashMap<Integer, ListNode> mp = new HashMap<>();

        while(itr != null)
        {
            csum += itr.val;

            if(csum == 0)
            {
                head = itr.next;
                mp.clear();
            }

            else if(mp.containsKey(csum))
            {
                sanitizeMap(mp.get(csum).next, mp, csum);
                mp.get(csum).next = itr.next;
            }

            else  
            {
                mp.put(csum, itr);
            }

            itr = itr.next;
        }
        return head;
    }


