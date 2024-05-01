// Leet-Code : Q.No => 2000 => Reverse Prefix of a Word => 1st May


    //  string stl + 2 pointer 


    // 1.******* Using C++ *******  


    // *** Approach - 1 ****  

    string reversePrefix(string word, char ch) 
    {
        int index = -1;

        // Iterate over the string to find the index of the character 'ch'
        for(int i=0;i<word.size();i++)
        {
            if(ch == word[i])
            {
                index = i;
                break;
            }
        }

        // If the character 'ch' is found 
        if(index != -1)
        {
            // Reverse the prefix of the word up to the index
            int i = 0;
            int j = index;

            while(i < j)
            {
                swap(word[i],word[j]);
                i++;
                j--;    
            }
        }

        return word;
    }


    // *** APproach - 2 *** 


    string reversePrefix(string word, char ch) 
    {
        int index = -1;

        // Iterate over the string to find the index of the character 'ch'
        for(int i=0;i<word.size();i++)
        {
            if(ch == word[i])
            {
                index = i;
                break;
            }
        }

        // If the character 'ch' is found 
        if(index != -1)
        {
            // Reverse the prefix of the word up to the index
            int i = 0;
            int j = index;

            while(i < j)
            {
                swap(word[i],word[j]);
                i++;
                j--;    
            }
        }

        return word;
    }





    // 2.******* Using Java *******  


    public String reversePrefix(String word, char ch) 
    {
        int index = word.indexOf(ch); // Find the index of the character 'ch' in the word

        // If the character is found
        if (index != -1) 
        {   
            StringBuilder sb = new StringBuilder(word.substring(0, index + 1)); // Create a StringBuilder with the prefix up to the index
            sb.reverse(); // Reverse the prefix
            sb.append(word.substring(index + 1)); // Append the remaining part of the word
            return sb.toString(); // Return the modified word
        }

        return word; // Return the original word if the character is not found
    }
