// Leet-Code : Q.No => 345 => Reverse Vowels of a String =>  -> 17th March 2024 


    // 2 pointer + string 


    // 1.******* Using C++ *******

    // Function to check if a character is a vowel
    bool isVowel(char c)
    {
        // Convert character to lowercase for case insensitivity
        c = tolower(c);

        //  Check if the character is one of the vowels
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }

        return false;
    }

    // Function to reverse the vowels in a string
    string reverseVowels(string s) 
    {
        
        // Initialize two pointers, one pointing to the start of the string and the other to the end
        int start = 0;
        int end = s.length() - 1;

        // Loop until the start pointer is less than the end pointer
        while(start < end)
        {
            // If both characters at start and end pointers are vowels
            if(isVowel(s[start]) && isVowel(s[end]))
            {
                swap(s[start],s[end]);
                start++;
                end--;
            }
            else if(!isVowel(s[start]))
            {
                start++;
            }
            else if(!isVowel(s[end]))
            {
                end--;
            }
        }  

        return s;         
    }





    // 2.******* Using Java *******

    public static boolean isVowel(char ch)
    {
        ch = Character.toLowerCase(ch);

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            return true;
        }

        return false;
    }

    public String reverseVowels(String s) 
    {
        int start = 0;
        int end = s.length() - 1;

        char ch[] = s.toCharArray();

        while(start < end)
        {
            if(isVowel(ch[start])  &&  isVowel(ch[end]))
            {
                // swap 
                char temp = ch[start];
                ch[start] = ch[end];
                ch[end] = temp;

                // update ptr
                start++;
                end--;
            }
            else if(!isVowel(ch[start]))
            {
                start++;
            }
            else if(!isVowel(ch[end]))
            {
                end--;
            }
        }

        return new String(ch);
    }