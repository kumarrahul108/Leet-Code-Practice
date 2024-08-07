
// Leet-Code : Q.No => 3016 => Minimum Number of Pushed to Type Word II  => 6 August



// 1.******* Using C++ *******

class Solution {
    public:
        int minimumPushes(string word) 
        {
            // Initialize a vector to store the frequency of each letter in the alphabet
            vector<int> letterFreq(26, 0);
            
            // Count the frequency of each letter in the input word
            for (char c : word) 
            {
                letterFreq[c - 'a']++;
            }
            
            // Sort the frequencies in descending order
            sort(letterFreq.rbegin(), letterFreq.rend());
            
            int totalPresses = 0;  // Variable to store the total number of key presses
            
            // Calculate the minimum number of key presses
            for (int i = 0; i < 26; i++) 
            {
                if (letterFreq[i] == 0) break;  // Stop if there are no more letters
                // Add the number of presses for this letter, considering it might be on a different key group
                totalPresses += (i / 8 + 1) * letterFreq[i];
            }
            
            return totalPresses;  // Return the total number of key presses
        }
    };




// 2.******* Using Java *******

class Solution {
    public int minimumPushes(String word) 
    {
        int freq[] = new int[26];
        for(char ch : word.toCharArray())
        {
            freq[ch - 'a']++;
        }    

        Integer sortedFreq[] = new Integer[26];
        for(int i=0;i<26;i++)
        {
            sortedFreq[i] = freq[i];
        }

        Arrays.sort(sortedFreq , Collections.reverseOrder());

        int count = 0;
        for(int i=0;i<26;i++)
        {
            if(sortedFreq[i] == 0) 
            {
                break;
            }

            count += (i/8 + 1) * sortedFreq[i];
        }

        return count;
    }
}