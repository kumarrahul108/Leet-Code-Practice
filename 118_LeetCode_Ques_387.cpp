// Leet-Code : Q.No => 387 => First Unique Character in a String => 30th April


    //  queue + hashmap + string 


    // 1.******* Using C++ *******   

    
    // *** Using Queue ****

    int firstUniqChar(string s) 
    {
        // Map to store the count of each character
        unordered_map<char,int> count;

        // Queue to store indices of unique characters
        queue<int> uniqueIndices;

        // Count the occurrences of each character in the string
        for(char c : s)
        {
            count[c]++;
        }    

        // Iterate through the string to find unique characters and their indices
        for(int i=0;i<s.length();i++)
        {
            // If the count of the current character is 1, it's unique
            if(count[s[i]] == 1)
            {
                // Store the index of the unique character
                uniqueIndices.push(i);
            }
        }

        // If the queue is empty, no unique character was found
        if(uniqueIndices.empty())
        {
            return -1;
        }

        // Otherwise, return the index of the first unique character
        return uniqueIndices.front();
    }



    // **** using Mapping ****


    int firstUniqChar(string s) 
    {
        // Create a vector to store the count of each character
        vector<int> mp(26, 0); // Initialize all counts to zero

        // Count the occurrences of each character in the string
        for(auto i : s) 
        {
            mp[i - 'a']++;  // Increment the count of the corresponding character
        }        

        // Iterate through the string to find the first unique character
        for(int i = 0; i < s.length(); i++) 
        {
            // If the count of the current character is 1, it's unique
            if(mp[s[i] - 'a'] == 1) 
            {
                return i; // Return the index of the first unique character
            }
        }

        return -1; // Return -1 if no unique character is found
    }






    // 2.******* Using Java *******  


    public int firstUniqChar(String s) 
    {
        HashMap<Character,Integer> count = new HashMap<>();
        Queue<Integer> uniqueIndices = new LinkedList<>();

        for(char c : s.toCharArray())
        {
            count.put(c, count.getOrDefault(c, 0) + 1);
        }    

        for(int i=0;i<s.length();i++)
        {
            if(count.get(s.charAt(i)) == 1)
            {
                uniqueIndices.offer(i);
            }
        }

        if(uniqueIndices.isEmpty())
        {
            return -1;
        }

        return uniqueIndices.peek();
    }
