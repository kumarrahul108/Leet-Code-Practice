
// Leet-Code : Q.No => 1750 => Minimum length of string after deleting similar ends -> 5th March 2024 


    // 1. Using C++ 


    // 2-pointer Approach 
    int minimumLength(string s) 
    {
       int left = 0;
       int right = s.size() - 1;

        while (left < right) 
        {
            if (s[left] != s[right]) 
            {
                // If characters at left and right positions are different, return the remaining length
                return right - left + 1;
            }

            // Skip identical characters from both ends
            while (left < right && s[left] == s[left + 1]) 
            {
                left++;
            }

            while (left < right && s[right] == s[right - 1]) 
            {
                right--;
            }

            // Move pointers towards the middle
            left++;
            right--;
        }

        // If left and right meet or cross each other, return 0 (no remaining characters)
        return left == right ? 1 : 0;
    }




    // 2. Using Java 

    public int minimumLength(String s) 
    {
        int left = 0;
        int right = s.length()-1;

        while(left < right)
        {
            if(s.charAt(left) != s.charAt(right))
            {
                return (right - left + 1);
            }

            while(left < right  && s.charAt(left) == s.charAt(left+1))
            {
                left++;
            } 

            while(left < right  && s.charAt(right) == s.charAt(right-1))
            {
                right--;
            } 

            left++;
            right--;
        }

        return left == right ? 1 : 0;

    }


    