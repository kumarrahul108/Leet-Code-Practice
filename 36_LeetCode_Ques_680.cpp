// Leet-Code : Q.No => 680 => Valid Palindrome - II  -> 15th March 2024 


    // 1.******* Using C++ ******* 

    // Function to check if a substring of string s from index i to j is a palindrome
    bool checkPalindrome(string s, int i ,int j)
    {
        while(i <= j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            else 
            {
                i++;
                j--;
            }
        }
        return true;
    }
    
    // Function to check if the given string s can be made a valid palindrome by removing at most one character
    bool validPalindrome(string s) 
    {
        int i = 0;
        int j = s.size() - 1;

        while(i < j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else 
            {
                // s[i] != s[j]
                // 1 removal allowed 
                // check pallindrome for string after removal

                // ith charcater -> remove
                 // 1. Remove the character at index i and check if the remaining substring is a palindrome.
                bool ans1 = checkPalindrome(s,i+1,j);

                // jth character -> remove
                // 2. Remove the character at index j and check if the remaining substring is a palindrome.
                bool ans2 = checkPalindrome(s,i,j-1);

                return (ans1 || ans2);
            }
        }  

        // agar yaha tak pahuche then valid palindrome hoga
        return true;  // If either of the two cases results in a palindrome, return true.
    }




    // 2. *** Using Java *******

    public boolean checkPalindrome(String s,int i,int j)
    {
        while(i <= j)
        {
            if(s.charAt(i) != s.charAt(j))
            {
                return false;
            }
            else 
            {
                i++;
                j--;
            }
        } 

        return true;      
    }


    public boolean validPalindrome(String s) 
    {
        int i = 0;
        int j = s.length() - 1;

        while(i < j)
        {
            if(s.charAt(i) == s.charAt(j))
            {
                i++;
                j--;
            }
            else 
            {
                // 1. 
                boolean ans1 = checkPalindrome(s,i+1,j);

                // 2. 
                boolean ans2 = checkPalindrome(s,i,j-1);

                return (ans1 || ans2);
            }
        }

        return true;
    }

