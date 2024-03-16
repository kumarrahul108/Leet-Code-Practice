// Leet-Code : Q.No => 890 =>  Find and Replace Pattern =>  -> 16th March 2024 


    // array + hasmap + string stl 


    // 1.******* Using C++ *******

    // This function creates a mapping for characters in the input string `str`.
    void createMapping(string &str)
    {
        char start = 'a';  // Initialize a starting character for mapping
        char map[256] = {0};   // Initialize an array to store mappings for characters

        // Iterate through each character in the input string `str`
        for(auto ch : str)
        {
            // If the character is not already mapped
            if(map[ch] == 0)
            {
                map[ch] = start++;   // Map the character to the next available character
                start++;  // Move to the next available character
            }
        }

        // Update the input string `str` with the mapped characters
        for(int i=0;i<str.size();i++)
        {
            char ch = str[i];
            str[i] = map[ch];
        }
    }


    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string> ans;

        // Normalize the pattern using character mapping
        createMapping(pattern); 

        // Iterate through each word in the vector `words
        for(string s : words)
        {
            string tempstr = s;  // Create a temporary copy of the word

            // Normalize the temporary string using character mapping
            createMapping(tempstr);

            if(tempstr == pattern)
            {
                ans.push_back(s);
            }
        }

        return ans;
    }



    // 2.******* Using Java *******

    public List<String> findAndReplacePattern(String[] words, String pattern) 
   {
        List<String> ans = new ArrayList<>();

        // Normalize the pattern using character mapping
        String normalizedPattern = createMapping(pattern);

        // Iterate through each word in the array `words`
        for (String word : words) 
        {
            // Normalize the current word using character mapping
            String normalizedWord = createMapping(word);

            // If the normalized word matches the normalized pattern
            if (normalizedWord.equals(normalizedPattern)) 
            {
                ans.add(word); // Add the original word to the result list
            }
        }

        return ans; // Return the result list
    }

    // This method creates a mapping for characters in the input string `str`.
    private String createMapping(String str) 
    {
        char start = 'a'; // Initialize a starting character for mapping
        char[] map = new char[256]; // Initialize an array to store mappings for characters

        StringBuilder normalizedStr = new StringBuilder();

        // Iterate through each character in the input string `str`
        for (char ch : str.toCharArray()) 
        {
            // If the character is not already mapped
            if (map[ch] == 0) 
            {
                map[ch] = start; // Map the character to the next available character
                start++; // Move to the next available character
            }
            normalizedStr.append(map[ch]);
        }

        return normalizedStr.toString(); // Return the normalized string
    }


