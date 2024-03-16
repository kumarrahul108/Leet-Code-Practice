// Leet-Code : Q.No => 647 => Palindromic Substrings -> 16th March 2024 


    // 2 pointer approach


    // 1.******* Using C++ ******* 

    int expand(string s,int i, int j) 
    {
        int count = 0;

        // Expand around the center defined by indices i and j
        while(i >= 0 && j < s.length() && s[i] == s[j] ) 
        {
            count++;  // Increment count for each valid palindrome found
            i--;     // Move left pointer towards left
            j++;     // Move right pointer towards right
        }

        return count;  // Return the count of palindromes found
    }

    int countSubstrings(string s) 
    {
        int totalCount = 0;

         // Iterate through each character in the string
        for(int i = 0; i < s.length(); i++ ) 
        {
            // Odd length palindromes centered at index i
            int j = i;
            int oddKaAns = expand(s, i, j);  // Count odd-length palindromes 

            // Even length palindromes centered at indices i and i+1
            j = i+1;
            int evenKaAns = expand(s, i, j);   // Count even-length palindromes

            // Update totalCount with the count of both odd and even palindromes
            totalCount = totalCount + oddKaAns + evenKaAns;
        }
        return totalCount;
    }




    // ***** 2. Using Java ***** 

    public int expand(String s ,int i , int j)
    {
        int count = 0;

        while(i >= 0 && j < s.length()  && s.charAt(i) == s.charAt(j))
        {
            count++;
            i--;
            j++;
        }

        return count;
    }

    public int countSubstrings(String s) 
    {
        int totalAns = 0;

        for(int i=0;i<s.length();i++)
        {
            int odd = expand(s,i,i);

            int even = expand(s,i,i+1);

            totalAns = totalAns + odd + even;
        }

        return totalAns;
    }