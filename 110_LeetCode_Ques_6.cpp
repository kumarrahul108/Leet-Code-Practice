// Leet-Code : Q.No => 6 => ZigZag Conversion => 23rd April


    // string + vector-string



    // 1.******* Using C++ *******


    string convert(string s, int numRows) 
    {
        // Base case: If numRows is 1, return the original string
        if (numRows == 1)
        {
            return s;
        }

        // Initialize variables
        vector<string> zigzag(numRows); // Vector of strings to store characters in each row
        int i = 0, row = 0; // Initialize index i and row number
        bool direction = true; // Initialize direction flag (true for top to bottom)

        // Infinite loop until all characters of the string are processed
        while (true)
        {
            // If direction is true (top to bottom)
            if (direction)
            {
                // Move from top to bottom in the zigzag pattern
                while (row < numRows && i < s.size())
                {
                    zigzag[row++].push_back(s[i++]); // Push the character to the current row and move to the next row
                }

                row = numRows - 2; // Move row pointer to the second last row for the next phase (bottom to top)
            }
            else // If direction is false (bottom to top)
            {
                // Move from bottom to top in the zigzag pattern
                while (row >= 0 && i < s.size())
                {
                    zigzag[row--].push_back(s[i++]); // Push the character to the current row and move to the previous row
                }
                row = 1; // Move row pointer to the second row for the next phase (top to bottom)
            }

            // If all characters are processed, break the loop
            if (i >= s.size())
            {
                break;
            }

            // Change direction for the next phase
            direction = !direction;
        }

        // Concatenate characters from each row to form the final result
        string ans = "";
        for (int i = 0; i < zigzag.size(); i++)
        {
            ans += zigzag[i];
        }

        return ans; // Return the final string in zigzag pattern
    }




    // 2.******* Using Java *******


    public String convert(String s, int numRows) 
    {
        // Base case: If numRows is 1, return the original string
        if (numRows == 1) 
        {
            return s;
        }

        // Initialize variables
        List<StringBuilder> zigzag = new ArrayList<>();
        for (int i = 0; i < numRows; i++) 
        {
            zigzag.add(new StringBuilder());
        }
        int i = 0, row = 0;
        boolean direction = true;

        // Infinite loop until all characters of the string are processed
        while (true) 
        {
            // If direction is true (top to bottom)
            if (direction) 
            {
                // Move from top to bottom in the zigzag pattern
                while (row < numRows && i < s.length()) 
                {
                    zigzag.get(row).append(s.charAt(i));
                    row++;
                    i++;
                }
                row = numRows - 2; // Move row pointer to the second last row for the next phase (bottom to top)
            }
            else 
            {   // If direction is false (bottom to top)
                // Move from bottom to top in the zigzag pattern
                while (row >= 0 && i < s.length()) 
                {
                    zigzag.get(row).append(s.charAt(i));
                    row--;
                    i++;
                }
                row = 1; // Move row pointer to the second row for the next phase (top to bottom)
            }

            // If all characters are processed, break the loop
            if (i >= s.length()) 
            {
                break;
            }

            // Change direction for the next phase
            direction = !direction;
        }

        // Concatenate characters from each row to form the final result
        StringBuilder ans = new StringBuilder();
        for (StringBuilder sb : zigzag) 
        {
            ans.append(sb);
        }

        return ans.toString(); // Return the final string in zigzag pattern
    }

