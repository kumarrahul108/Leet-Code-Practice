// Leet-Code : Q.No => 165 => Compare Version Numbers => 3rd May


    //  string stl + 2 pointer + char arrays   


    // 1.******* Using C++ *******  


    int compareVersion(string version1, string version2) 
    {
        int idx1 = 0; // Index pointer for version1
        int idx2 = 0; // Index pointer for version2
        
        bool versionsLeft = true; // Flag to indicate if there are still versions left to compare

        // Continue until all versions are compared
        while (versionsLeft) 
        { 
            
            long long num1 = 0; // Initialize the number representing version1
            long long num2 = 0; // Initialize the number representing version2

            // Extract numbers from version1 until a dot or end of string is encountered
            while (idx1 < version1.length() && version1[idx1] != '.') 
            {
                num1 = num1 * 10 + version1[idx1] - '0'; // Convert character to integer and add to num1
                idx1++; // Move to the next character
            }

            // Extract numbers from version2 until a dot or end of string is encountered
            while (idx2 < version2.length() && version2[idx2] != '.') 
            {
                num2 = num2 * 10 + version2[idx2] - '0'; // Convert character to integer and add to num2
                idx2++; // Move to the next character
            }
           
            // Compare the extracted numbers
            if (num1 > num2) 
            {   // If version1 is greater than version2
                return 1; // Return 1
            } 
            else if (num1 < num2) 
            {   // If version1 is less than version2
                return -1; // Return -1
            }

            // If both versions are equal and there are no more characters left in either version
            if (idx1 >= version1.length() && idx2 >= version2.length()) 
            {
                return 0; // Return 0 indicating both versions are equal
            }
            
            // Move to the next character after the dot
            idx1++;
            idx2++;
        }

        return 0; // If all comparisons are done and no differences are found, return 0
    }






    // 2.******* Using Java *******  

    public int compareVersion(String version1, String version2) 
    {
        int idx1 = 0;    
        int idx2 = 0; 

        char []version11 = version1.toCharArray(); 
        char []version22 = version2.toCharArray(); 

        boolean versionLeft = true;

        while(versionLeft)
        {
            long num1 = 0;
            long num2 = 0;

            while(idx1 < version1.length() && version11[idx1] != '.')
            {
                num1 = num1 * 10 + version11[idx1] - '0';
                idx1++;
            }

            while(idx2 < version2.length() && version22[idx2] != '.')
            {
                num2 = num2 * 10 + version22[idx2] - '0';
                idx2++;
            }

            if(num1 > num2)
            {
                return 1;
            }
            else if(num1 < num2)
            {
                return -1;
            }

            if(idx1 >= version1.length() && idx2 >= version2.length())
            {
                return 0;
            }

            idx1++;
            idx2++;
        }  

        return 0;
    }
