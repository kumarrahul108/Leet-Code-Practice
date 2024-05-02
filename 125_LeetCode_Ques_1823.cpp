// Leet-Code : Q.No => 1823 => Find the Winner of the Circular Game => 2nd May


    //  queue stl + array   


    // 1.******* Using C++ *******  


    int findTheWinner(int n, int k) 
    {
        // all players should go intoa Queue
        queue<int> q;
        for(int i=1;i<=n;i++)
        {
            q.push(i);
        }        

        // simulate the Queue
        while(q.size() > 1)
        {
            for(int i=1;i<k;i++)
            {
                auto player = q.front();
                q.pop();

                // it is not elimaneted
                q.push(player);
            }

            // kth player must be eliminated
            q.pop();
        }

        return q.front();   // winner 
    }       





    // 2.******* Using Java *******  


    public int findTheWinner(int n, int k) 
    {
        // Create a queue to store players
        Queue<Integer> q = new LinkedList<>();
        
        // Add players to the queue
        for (int i = 1; i <= n; i++) 
        {
            q.add(i);
        }
        
        // Simulate the queue
        while (q.size() > 1) 
        {
            // Move (k-1) players to the end of the queue
            for (int i = 1; i < k; i++) 
            {
                int player = q.poll();
                q.add(player);
            }
            
            // Remove the kth player from the queue (eliminate)
            q.poll();
        }
        
        // Return the remaining player (the winner)
        return q.peek();
    }