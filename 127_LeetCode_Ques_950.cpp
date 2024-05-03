// Leet-Code : Q.No => 950 => Reveal Cards In Incresing Order => 3rd May


    //  queue + sorting + simulation of queue    


    // 1.******* Using C++ *******  


    vector<int> deckRevealedIncreasing(vector<int>& deck) 
    {
        sort(deck.begin(),deck.end());
        queue<int> q;

        vector<int> ans(deck.size());

        // put the indices of ans into queue
        for(int i=0;i<ans.size();i++)
        {
            q.push(i);
        }        

        // reverse simulation + filling using sorted deck 
        for(int i=0;i<deck.size();i++)
        {
            // 1.Reveal
            ans[q.front()] = deck[i];
            q.pop();

            // 2.Push front to bottom
            if(!q.empty())
            {
                auto f = q.front();
                q.pop();
                q.push(f);
            }  
        }
        
        return ans;
    }





    // 2.******* Using Java *******  


    public int[] deckRevealedIncreasing(int[] deck) 
    {
        Arrays.sort(deck); // Sort the deck in increasing order
        Queue<Integer> q = new LinkedList<>(); // Create a queue to store indices
        int n = deck.length;
        
        for (int i = 0; i < n; i++) 
        {
            q.offer(i); // Put the indices of the result array into the queue
        }
        
        int[] ans = new int[n];
        
        for (int card : deck) 
        {
            // Reveal the card by placing it at the front index
            ans[q.poll()] = card;
            
            // If there are still indices left in the queue, move the front index to the end
            if (!q.isEmpty()) 
            {
                q.offer(q.poll());
            }
        }
        
        return ans;
    }




