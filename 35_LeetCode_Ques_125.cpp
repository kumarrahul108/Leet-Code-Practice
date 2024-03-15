// Leet-Code : Q.No => 125 => Valid Palindrome =>  -> 15th March 2024 


    // 1.******* Using C++ *******

    bool isPalindrome(string s) 
    {
        int i = 0;
        int j = s.size()-1;

        // Loop until the two pointers meet or cross
        while(i <= j)
        {   
            // If character at i is not alphanumeric, move to the next character
            if(!isalnum(s[i]))
            {
                i++;
            }
            // If character at j is not alphanumeric, move to the previous character
            else if(!isalnum(s[j]))
            {
                j--;
            }
            // If characters at i and j are not equal (case insensitive), return false
            else if(tolower(s[i]) != tolower(s[j]))
            {
                return false;
            }
            // If characters at i and j are equal, move both pointers inward
            else 
            {
                i++;
                j--;
            }
        }
        return true;    // If the loop completes without returning false, it means the string is a palindrome

        // isalnum function is used to check whether a given character is alphanumeric or not. 
    }




    // 2. **** Using Java *******

    public boolean isPalindrome(String s) 
        {
            int i = 0;
            int j = s.length() - 1;

            // Loop until the two pointers meet or cross
            while (i <= j) 
            {   
                // If character at i is not alphanumeric, move to the next character
                if (!Character.isLetterOrDigit(s.charAt(i))) 
                {
                    i++;
                }

                // If character at j is not alphanumeric, move to the previous character
                else if (!Character.isLetterOrDigit(s.charAt(j))) 
                {
                    j--;
                }
            
                // If characters at i and j are not equal (case insensitive), return false
                else if (Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j))) 
                {
                    return false;
                }
        
                // If characters at i and j are equal, move both pointers inward
                else 
                {
                    i++;
                    j--;
                }
            }
            return true;    // If the loop completes without returning false, it means the string is a palindrome    
        }

    
