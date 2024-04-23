// Leet-Code : Q.No => 179 => Largest Number => 23rd April


    // 



    // 1.******* Using C++ *******      


    // Custom comparison function for sorting strings
    static bool myComp(string a, string b)
    {
        // Concatenate strings in two different orders  
        string t1 = a + b;
        string t2 = b + a;

        // Compare the concatenated strings lexicographically
        // Return true if t1 should appear before t2 in the sorted order
        return t1 > t2;
    }

    // Function to find the largest number formed by arranging the numbers in the input array
    string largestNumber(vector<int>& nums) 
    {
        // Convert integers to strings
        vector<string> snums;
        for(auto n : nums)
        {
            snums.push_back(to_string(n));
        }        

        // Sort the strings using the custom comparison function
        sort(snums.begin(), snums.end(), myComp);

        // If the largest number is "0", return "0"
        if(snums[0] == "0")
        {
            return "0";
        }

        // Concatenate sorted strings to form the largest number
        string ans = "";
        for(auto str : snums)
        {
            ans += str;
        }

        return ans; // Return the largest number formed
    }







    // 2.******* Using Java *******


    // Custom comparator for sorting strings
    static class MyComparator implements Comparator<String> {
        @Override
        public int compare(String a, String b) {
            // Concatenate strings in two different orders
            String t1 = a + b;
            String t2 = b + a;

            // Compare the concatenated strings lexicographically
            // Return -1 if t1 should appear before t2 in the sorted order
            // Return 1 if t1 should appear after t2 in the sorted order
            // Return 0 if the strings are equal
            return t2.compareTo(t1);
        }
    }

    // Function to find the largest number formed by arranging the numbers in the input array
    public String largestNumber(int[] nums) {
        // Convert integers to strings
        String[] snums = new String[nums.length];
        for (int i = 0; i < nums.length; i++) {
            snums[i] = Integer.toString(nums[i]);
        }

        // Sort the strings using the custom comparator
        Arrays.sort(snums, new MyComparator());

        // If the largest number is "0", return "0"
        if (snums[0].equals("0")) {
            return "0";
        }

        // Concatenate sorted strings to form the largest number
        StringBuilder ans = new StringBuilder();
        for (String str : snums) {
            ans.append(str);
        }

        return ans.toString(); // Return the largest number formed
    }

