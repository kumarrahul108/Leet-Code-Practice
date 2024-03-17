// Leet-Code : Q.No => 443 => String Compression  =>  -> 17th March 2024 


    // 2 pointer + string stl 


    // 1.******* Using C++ *******

    int compress(vector<char>& s) 
    {
        int index = 0;   // Index to track the position of the compressed characters
        int count = 1;   // Count of consecutive characters
        char prev = s[0];  // Previous character

        // Iterate through the characters starting from the second character
        for(int i=1;i<s.size();i++)
        {
            // If the current character is the same as the previous one, increment the count
            if(s[i] == prev)
            {
                count++;
            }

            // If the current character is different
            else 
            {
                s[index] = prev;   // Store the previous character at the current index
                index++;          // Move to the next index
                
                // If there are more than one occurrence of the previous character
                if(count > 1)
                {
                    int start = index;   // Starting index for storing the count digits
                    
                    // Store the count digits in reverse order
                    while(count)
                    {
                        s[index++] = (count % 10) + '0';  // Convert the digit to character and store
                        count /= 10;   // Move to the next digit
                    }

                    // Reverse the order of count digits to make it in the correct order
                    reverse(s.begin()+start,s.begin()+index); 
                }

                // Update the previous character and reset the count for the new character
                prev = s[i];
                count  = 1;
            }
        }  

        // Store the last character and its count (if count is greater than 1)
        s[index] = prev;
        index++;
        if(count > 1)
        {
            int start = index;

            while(count > 0)
            {
                s[index++] = (count % 10) + '0';
                count /= 10;
            }

            reverse(s.begin()+start,s.begin()+index);
        } 

        return index;   // Return the length of the compressed string           
    }




    // 2. ****** Using Java ****** 


    public int compress(char[] s) 
    {
        int index = 0;
        int count = 1;
        char prev = s[0];

        for (int i = 1; i < s.length; i++) 
        {
            if (s[i] == prev) 
            {
                count++;
            } 
            else 
            {
                s[index++] = prev;
                if (count > 1) 
                {
                    String countStr = String.valueOf(count);
                    for (char c : countStr.toCharArray()) 
                    {
                        s[index++] = c;
                    }
                }
                prev = s[i];
                count = 1;
            }
        }

        s[index++] = prev;
        if (count > 1) 
        {
            String countStr = String.valueOf(count);
            for (char c : countStr.toCharArray()) 
            {
                s[index++] = c;
            }
        }

        return index;    
    }