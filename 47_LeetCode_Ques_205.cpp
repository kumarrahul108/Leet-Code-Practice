// Leet-Code : Q.No => 205 => Isomorphic Strings =>  -> 17th March 2024 


    // string + hashing (mapping) 


    // 1.******* Using C++ *******

    bool isIsomorphic(string s, string t) 
    {
        // Initialize an array to store mappings from characters of string s to characters of string t
        int hash[256] = {0};

        // Initialize an array to keep track of characters in string t that have been mapped
        bool istCharMapped[256] = {0};

        // Iterate through the characters of string s
        for(int i=0;i<s.length();i++)
        {
            // Check if the mapping for character s[i] is not already present and if character t[i] has not been mapped
            if(hash[s[i]] == 0 && istCharMapped[t[i]] == 0)
            {
                hash[s[i]] = t[i]; // Map character s[i] to character t[i]
                istCharMapped[t[i]] = true; // Mark character t[i] as mapped
            }
        }   

        // Iterate through the characters of string s again to validate the mappings
        for(int i=0;i<s.length();i++)
        {
            // If the mapped character for s[i] doesn't match t[i], return false
            if(char(hash[s[i]]) != t[i])
            {
                return false;
            }
        }    

        return true;  // Return true if all characters are correctly mapped                
    }





    // 2.******* Using Java *******

    public boolean isIsomorphic(String s, String t) 
    {
        int[] hash = new int[256]; // Initialize an array to store mappings from characters of string s to characters of string t
        boolean[] isCharMapped = new boolean[256]; // Initialize an array to keep track of characters in string t that have been mapped

        // Iterate through the characters of string s
        for (int i = 0; i < s.length(); i++) 
        {
            // Check if the mapping for character s.charAt(i) is not already present and if character t.charAt(i) has not been mapped
            if (hash[s.charAt(i)] == 0 && !isCharMapped[t.charAt(i)]) 
            {
                hash[s.charAt(i)] = t.charAt(i); // Map character s.charAt(i) to character t.charAt(i)
                isCharMapped[t.charAt(i)] = true; // Mark character t.charAt(i) as mapped
            }
        }

        // Iterate through the characters of string s again to validate the mappings
        for (int i = 0; i < s.length(); i++) 
        {
            // If the mapped character for s.charAt(i) doesn't match t.charAt(i), return false
            if (hash[s.charAt(i)] != t.charAt(i)) 
            {
                return false;
            }
        }

        return true; // Return true if all characters are correctly mapped
    }    