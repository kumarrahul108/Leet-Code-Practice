// Leet-Code : Q.No => 12 => Integer to Roman  =>  -> 18th March 2024 


    // array + string 


    // 1.******* Using C++ *******

    string intToRoman(int num) 
    {
        // Arrays to hold Roman numeral symbols and their corresponding values
        string romanSymbols[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

        string ans = "";  // Initialize an empty string to hold the Roman numeral representation

        // Iterate through each symbol and its corresponding value
        for(int i=0;i<13;i++)
        {
            // While the value to be converted is greater than or equal to the current value
            while(num >= values[i])
            {
                ans = ans + romanSymbols[i];  // Append the corresponding symbol to the result string
                num = num - values[i];  // Subtract the value from the original number
            }
        }        

        return ans;  // Return the final Roman numeral representation
    }





    // 2.******* Using Java *******

    public String intToRoman(int num) 
    {
        
        // Arrays to hold Roman numeral symbols and their corresponding values
        String romanSymbols[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};  

        String ans = "";

        for(int i=0;i<13;i++)
        {
            while(num >= values[i])
            {
                ans += romanSymbols[i];
                num -= values[i];
            }
        }  

        return ans;        
    }