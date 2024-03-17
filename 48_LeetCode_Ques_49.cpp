// Leet-Code : Q.No => 49 => Group Anagrams  =>  -> 17th March 2024 


    // array + string + sorting + HashTable


    // 1.******* Using C++ *******


    // ****** Approach - 1 ****** 

    // this is similar to --> create maooing using array
    // int hash[256] = {0};  -> stl array is similar to it
    // Function to calculate the character frequency array for a string
    std::array<int,256> hash(string s)
    {
        std:: array<int,256> hash = {0};  // Initialize an array to store character frequencies

        // Iterate through the characters of the string
        for(int i=0;i<s.size();i++)    
        {
            hash[s[i]]++;
        }
        return hash;    // if mapped -> mark 1 , else mark by default -> 0
    }

    // Function to group anagrams
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        map<std::array<int,256> , vector<string> >  mp;   // Create a map to store anagrams with their character frequency array

        // Iterate through each string in the input vector
        for(auto str : strs)
        {
            mp[hash(str)].push_back(str);   // Map the character frequency array of the string to its anagram group
        }

        vector<vector<string>> ans;   // Initialize a vector to store the grouped anagrams

        // Iterate through the map and push back the vector of anagrams into the result vector
        for(auto it=mp.begin();it != mp.end();it++)
        {
            ans.push_back(it->second);
        }

        return ans;  // Return the grouped anagrams
    }



    // ***** Approach 2 ******* 

    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        // Create a map to store anagrams, with sorted strings as keys and vector of anagrams as values
        map<string,vector<string>> mp;

        // Iterate through each string in the input vector
        for(auto str : strs)
        {
            string s = str;
            sort(s.begin(),s.end());  // Sort the characters of the current string to identify anagrams
            mp[s].push_back(str);   // Add the original string to the corresponding key in the map
        }    
        
        // Initialize a vector of vectors to store the grouped anagrams
        vector<vector<string>> ans;

        // Iterate through the map and push back the vector of anagrams into the result vector
        for(auto it = mp.begin();it != mp.end();it++)
        {
            ans.push_back(it->second);
        }

        return ans;  // Return the grouped anagrams
    }







    // 2.******* Using Java *******

    public List<List<String>> groupAnagrams(String[] strs) 
    {
        Map<String , List<String>> map = new HashMap<>();

        for(String str : strs)
        {
            char charArray[] = str.toCharArray();
            Arrays.sort(charArray);
            String sortedStr = new String(charArray);

            map.computeIfAbsent(sortedStr, key -> new ArrayList<>()).add(str);
        }    

        List<List<String>> result = new ArrayList<>();

        for (List<String> anagrams : map.values()) 
        {
            result.add(anagrams);
        }

        return result;
    }