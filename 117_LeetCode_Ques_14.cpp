// Leet-Code : Q.No => 14 => Longest Common Prefix => 29th April


    // striing 


    // 1.******* Using C++ *******   


    string longestCommonPrefix(vector<string>& strs) 
    {
        string ans; // Initialize an empty string to store the longest common prefix
        int i = 0; // Initialize a variable to keep track of the current character index

        // Continue iterating until a mismatch is found or the end of any string is reached
        while (true) 
        {
            char curr_ch = 0; // Initialize a variable to store the current character

            // Iterate over each string in the vector
            for (auto str : strs) 
            {
                // Check if the current index is out of bounds for the current string
                if (i >= str.size()) 
                { 
                    curr_ch = 0; // If out of bounds, set current character to 0 and break the loop
                    break;
                }

                // If this is the first string or the current character matches the previous strings
                if (curr_ch == 0) 
                {
                    curr_ch = str[i]; // Set the current character to the character at index i
                } 
                else if (str[i] != curr_ch) 
                {   
                    // If there's a mismatch with previous characters
                    curr_ch = 0; // Set current character to 0 and break the loop
                    break;
                }
            }

            // If current character is 0, indicating a mismatch or end of any string, break the loop
            if (curr_ch == 0) 
            {
                break;
            }

            // Otherwise, append the current character to the result
            ans.push_back(curr_ch);
            i++; // Move to the next character index
        }

        return ans; // Return the longest common prefix
    }





    // 2.******* Using Java *******   