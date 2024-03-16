// Leet-Code : Q.No 2325 =>  => Decode the Message -> 16th March 2024 


    // Hash Map + string stl 


    // 1.******* Using C++ *******

    string decodeMessage(string key, string message) 
    {
        // Create mapping between characters in the key and characters starting from 'a'
        char start = 'a';
        char mapping[256] = {0};   // Initialize array to store mapping, assuming ASCII characters

        // Populate mapping based on the key
        for(auto ch : key)
        {
            // Ignore spaces in the key and check if character hasn't been mapped yet
            if(ch != ' ' && mapping[ch] == 0)
            {
                mapping[ch] = start;   // Map character to current value of 'start'
                start++;   // Increment 'start' for next unmapped character
            }
        }   


        // Use mapping to decode the message
        string ans = "";
        for(int i=0;i<message.length();i++)
        {
            char ch = message[i];

            // If character is a space, append space to decoded message
            if(ch == ' ')
            {
                ans.push_back(' ');
            }
            else 
            {
                // Retrieve mapped character from the mapping and append to decoded message
                char c = mapping[ch];
                ans.push_back(c);
            }
        } 

        return ans;   // Return the decoded message
    }



    // 2.******* Using Java *******

    public String decodeMessage(String key, String message) 
    {
        // create mapping 
        char map[] = new char[256];
        char start = 'a';

        for(char ch : key.toCharArray())
        {
            if(ch != ' '  &&  map[ch] == 0)
            {
                map[ch] = start;
                start++;
            }
        }  

        String ans = "";
        // decode the mesaage using map
        for(char ch : message.toCharArray())
        {
            if(ch == ' ')
            {
                ans += " ";
            }
            else 
            {
                ans += map[ch];
            }
        } 

        return ans;  
    }


