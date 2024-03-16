// Leet-Code : Q.No => 791 =>  Custom Sort String =>  -> 16th March 2024 


    // hash map + string stl 


    // 1.******* Using C++ *******

    string customSortString(string order, string s) 
    {
        // Count the frequency of characters in s
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;

        // Reorder characters in s according to the order in order
        string result = "";
        for (char c : order) 
        {
            if (freq.find(c) != freq.end()) 
            {
                result.append(freq[c], c);
                freq.erase(c); // Remove the character from the frequency map
            }
        }

        // Append remaining characters from s that are not in order
        for (auto it : freq)
            result.append(it.second, it.first);

        return result;   

        // result.append(it.second, it.first): This appends it.second occurrences of the character it.first to the result string. In other words, it adds the character it.first to the result string it.second times. 
    }



    // 2.******* Using Java *******

    public String customSortString(String order, String s) 
    {
        // Count the frequency of characters in s
        HashMap<Character, Integer> freq = new HashMap<>();
        for (char c : s.toCharArray()) 
        {
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }

        // Reorder characters in s according to the order in order
        StringBuilder result = new StringBuilder();
        for (char c : order.toCharArray()) 
        {
            if (freq.containsKey(c)) 
            {
                result.append(String.valueOf(c).repeat(freq.get(c)));
                freq.remove(c); // Remove the character from the frequency map
            }
        }

        // Append remaining characters from s that are not in order
        for (char key : freq.keySet()) 
        {
            int count = freq.get(key);
            for (int i = 0; i < count; i++) 
            {
                result.append(key);
            }
        }

        return result.toString();    
    }


