// Leet-Code : Q.No => 767 => Reorganize String => 29th April


    // Greedy Approach + Hash Table + Counting 


    // 1.******* Using C++ *******   

    string reorganizeString(string s)   
    {
        int hash[26] = {0};

        // Count the frequency of each character
        for (char ch : s) 
        {
            hash[ch - 'a']++;
        }

        char max_freq_char = 'a';
        int max_freq = INT_MIN;

        // Find the character with maximum frequency
        for (int i = 0; i < 26; i++) 
        {
            if (hash[i] > max_freq) 
            {
                max_freq = hash[i];
                max_freq_char = i + 'a';
            }
        }            

        int index = 0;
        // Place the most frequent character at even indices
        while (max_freq > 0 && index < s.size()) 
        {
            s[index] = max_freq_char;
            max_freq--;
            index += 2;
        }

        if (max_freq != 0) 
        {
            return ""; // Impossible to rearrange
        }

        hash[max_freq_char - 'a'] = 0;

        // Place the remaining characters at odd indices
        for (int i = 0; i < 26; i++) 
        {
            while (hash[i] > 0) 
            {
                index = (index >= s.size()) ? 1 : index; // Reset index to 1 if it exceeds the string size
                s[index] = i + 'a';
                hash[i]--;
                index += 2;    
            }
        }  

        return s; 
    }






    // 2.******* Using Java *******   

    public String reorganizeString(String s) 
    {
        int hash[] = new int[26];

        // Count the frequency of each character
        for(char ch : s.toCharArray())
        {
            hash[ch - 'a']++;
        }   

        char maxFreqChar = 'a';
        int maxFreq = Integer.MIN_VALUE;

        // Find the character with maximum frequency
        for(int i=0;i<26;i++)
        {
            if(hash[i] > maxFreq)
            {
                maxFreq = hash[i];
                maxFreqChar = (char)(i + 'a');            
            }
        }

        int index = 0;
        char charArray[] = s.toCharArray();
        
        // Place the most frequent character at even indices
        while(maxFreq > 0 && index < s.length())
        {
            charArray[index] = maxFreqChar;
            maxFreq--;
            index += 2;
        }

        if(maxFreq != 0)
        {
            return "";
        }

        hash[maxFreqChar - 'a'] = 0;

        // Place the remaining characters at odd indices
        for(int i=0;i<26;i++)
        {
            while(hash[i] > 0)
            {
                index = (index >= s.length()) ? 1 : index;
                charArray[index] = (char)(i + 'a');
                hash[i]--;
                index += 2;
            }
        }

        return new String(charArray);
    }
