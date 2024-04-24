// Leet-Code : Q.No => 28 => Find the Index of the First Occurrence in a String => 24th April


    // sliding window approach + substring approach 


    // 1.******* Using C++ *******      


    // **** approach - 1 *****


    int strStr(string haystack, string needle) 
    {
        int m = haystack.size(); // Get the length of haystack          
        int n = needle.size();   // Get the length of needle

        // Loop through haystack
        for(int i = 0; i <= (m - n); i++)
        {
            // Loop through needle
            for(int j = 0; j < n; j++)
            {
                // Check if characters match
                if(needle[j] != haystack[i + j])
                {
                    break; // If characters don't match, break out of the inner loop
                }
                // If we reached the end of needle, it means we found a match
                if(j == (n - 1))
                {
                    return i; // Return the index where needle starts in haystack
                }
            }
        } 

        return -1; // If needle is not found in haystack, return -1           
    }




    // **** approach - 2 *****

    int strStr(string haystack, string needle) 
    {
        int m = haystack.size();
        int n = needle.size();

        // edge cases 
        if(needle.size() == 0)
        {
            return 0;
        }

        if(haystack.size() < needle.size())
        {
            return -1;
        }

        // loop 
        for(int i=0;i<=(m-n);i++)
        {
            // substring lo check 
            if(haystack.substr(i, needle.length()) == needle)
            {
                return i;
            }
        }

        return -1;
    }






    // 2.******* Using Java ******* 


    public int strStr(String haystack, String needle) 
    {
        int m = haystack.length();        
        int n = needle.length();

        // Iterate through haystack
        for (int i = 0; i <= m - n; i++) 
        {
            // Iterate through needle
            for (int j = 0; j < n; j++) 
            {
                // Check if characters at current positions match
                if (needle.charAt(j) != haystack.charAt(i + j)) 
                {
                    break; // If not, break out of the inner loop
                }

                // If we reach the end of needle, it means we found a match
                if (j == n - 1) 
                {
                    return i; // Return the starting index of the match
                }
            }
        }

        return -1;        
    }