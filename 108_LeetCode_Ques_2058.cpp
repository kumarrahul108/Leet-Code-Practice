// Leet-Code : Q.No => 2058 => Find the Minimum and Maximum Number of Nodes Between Critical Points => 22nd April


    // list traversal + array + min-max value + critical point   



    // 1.******* Using C++ *******


    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        vector<int> ans = {-1, -1}; // Initialize the answer vector with default values for minDist and maxDist

        // Base case: If head is NULL or only one node exists, return the default answer
        ListNode* prev = head;
        if (prev == NULL || prev->next == NULL)
        {
            return ans;
        }  

        // Set up pointers for the current and next nodes
        ListNode* curr = head->next;
        ListNode* nxt = head->next->next;

        // If next node is NULL, return the default answer
        if (!nxt)
        {
            return ans;
        }

        // Initialize variables to track the first and last critical points, and the minimum distance
        int firstCP = -1;
        int lastCP = -1;
        int minDist = INT_MAX; // Initialize minDist to the maximum possible integer value
        int i = 1; // Counter for node index

        // Loop through the list
        while (nxt)
        {
            // Check if the current node is a critical point
            bool isCP = ((curr->val > prev->val && curr->val > nxt->val) 
                         || (curr->val < prev->val && curr->val < nxt->val)) ? true : false;

            // If the current node is a critical point and it's the first one encountered
            if (isCP && firstCP == -1)
            {
                firstCP = i;
                lastCP = i;
            } 
            // If the current node is a critical point and it's not the first one encountered
            else if(isCP) 
            {
                minDist = min(minDist, i - lastCP); // Update minDist
                lastCP = i; // Update last critical point index
            } 

            // Update pointers and index
            i++;      
            prev = prev->next;
            curr = curr->next;
            nxt = nxt->next;     
        }

        // If no critical points were found or only one critical point exists, return the default answer
        if (lastCP == firstCP)
        {
            return ans;
        }
        // Otherwise, update the answer vector with the calculated minDist and maxDist
        else 
        {
            ans[0] = minDist;
            ans[1] = lastCP - firstCP;
        }

        return ans; // Return the answer vector
    }








    // 2.******* Using Java *******

    public int[] nodesBetweenCriticalPoints(ListNode head) 
    {
        int ans[] = {-1,-1};

        // base case 

        // prev exist 
        ListNode prev = head;
        if(prev == null)
        {
            return ans;
        } 

        // curr exist
        ListNode curr = head.next;
        if(curr == null)
        {
            return ans;
        }

        // next exist
        ListNode nxt = head.next.next;
        if(nxt == null)
        {
            return ans;
        }

        // initialise variables 
        int firstCP = -1;
        int lastCP = -1;
        int minDist = Integer.MAX_VALUE;
        int i = 1;

        while(nxt != null)
        {
            boolean isCP = ((curr.val > prev.val && curr.val > nxt.val)
                        || (curr.val < prev.val && curr.val < nxt.val))
                            ? true : false;

            if(isCP == true && firstCP == -1)
            {
                firstCP = i;
                lastCP = i;
            }  
            else if(isCP)
            {
                minDist = Math.min(minDist,i - lastCP);
                lastCP = i;
            }           

            // update ptrs
            i++;
            prev = prev.next;   
            curr = curr.next;   
            nxt = nxt.next;    
        }

        if(firstCP == lastCP)
        {
            return ans;
        }
        else 
        {
            ans[0] = minDist;
            ans[1] = lastCP - firstCP;
        }

        return ans;
    }
