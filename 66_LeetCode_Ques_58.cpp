// Leet-Code : Q.No => 58 => Length of Last Word => 1st April 2024 


    //  using strings stl  


    // 1.******* Using C++ *******

    

    // **** Approaxch - 1 *** 

    int lengthOfLastWord(string s) 
    {
        // Variable to store the length of the last word
        int len = 0;

        // Iterate the string from the end
        for(int i=s.size()-1;i>=0;i--)
        {
            // Skip leading spaces
            if(s[i] == ' '  &&  len == 0)
            {
                continue;
            }

            // If we encounter a space and already counted characters
            if(s[i] == ' ' && len != 0)
            {
                // return len;
                break;   // Break the loop because we've counted the last word
            }

            // If the character is not a space
            if(s[i] != ' ')
            {
                len++;  // Increment the length of the last word
            }
        }

        return len;   // Return the length of the last word
    }



    // **** Approaxch - 2 ***

    int lengthOfLastWord(string s) 
    {
        int length = 0; // Variable to store the length of the last word
        bool counting = false; // Flag to indicate whether we are counting characters of the last word

        // Iterate the string from the end
        for (int i = s.length() - 1; i >= 0; i--) 
        {
            // If the character is not a space
            if (s[i] != ' ') 
            {             
                counting = true; // Start counting
                length++; // Increment the length of the last word
            } 
            // If we encounter a space and we were already counting characters
            else if (counting) 
            { 
                break; // Break the loop because we've counted the last word
            }
        }

        return length; // Return the length of the last word    
    }





    // 2.******* Using Java *******

    public int lengthOfLastWord(String s) 
    {
        int len = 0;

        for(int i=s.length() - 1;i>=0;i--)
        {
            if(s.charAt(i) == ' ' && len == 0)
            {
                continue;
            }

            if(s.charAt(i) == ' ' && len != 0)
            {
                break;
            }

            if(s.charAt(i) != ' ')
            {
                len++;
            }
        }    

        return len;
    }