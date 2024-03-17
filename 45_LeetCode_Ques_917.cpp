// Leet-Code : Q.No => 917 => Reverse Only Letters  =>  -> 16th March 2024 


    // 2 poniter + stl to check only letters + swap 


    // 1.******* Using C++ *******

    string reverseOnlyLetters(string s) 
    {
        // Initialize two pointers, 'start' pointing to the beginning of the string and 'end' pointing to the end of the string
        int start = 0;
        int end = s.size() - 1;

        // Continue swapping characters until 'start' pointer is less than 'end' pointer
        while(start < end)
        {
            // If both characters at 'start' and 'end' positions are letters, swap them
            if(isalpha(s[start]) && isalpha(s[end]))
            {
                swap(s[start] , s[end]);
                start++;
                end--;
            }

            // If the character at 'start' position is not a letter, move 'start' pointer forward
            else if(!isalpha(s[start]))
            {
                start++;
            }

            // If the character at 'end' position is not a letter, move 'end' pointer backward
            else if(!isalpha(s[end]))
            {
                end--;
            }
        }

        return s;   // Return the modified string after reversing only the letters
    }



    // 2.******* Using Java *******

    public String reverseOnlyLetters(String s) 
    {
        // Convert string to char array for easier manipulation
        char chars[] = s.toCharArray();

        int start = 0;
        int end = s.length() - 1;

        while(start < end)
        {
            // If both characters at 'start' and 'end' positions are letters, swap them
            if(Character.isLetter(chars[start])  &&  Character.isLetter(chars[end]))
            {
                // swap 
                char temp = chars[start];
                chars[start] = chars[end];
                chars[end] = temp;

                // update ptr
                start++;
                end--;
            }
            else if(!Character.isLetter(chars[start]))
            {
                start++;
            }
            else if(!Character.isLetter(chars[end]))
            {
                end--;
            }
        } 

        // Convert char array back to string
        return new String(chars);
    }