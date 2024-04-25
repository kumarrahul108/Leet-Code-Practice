// Leet-Code : Q.No => 2125 => Number of Laser Beams in a Bank => 25th April


    // string + array + matrix


    // 1.******* Using C++ *******    

    // Function to count the number of devices in a binary string
    int countDevices(string &binary)
    {
        int c = 0; // Initialize count to 0
        // Iterate through each character in the binary string
        for(auto b : binary)
        {
            c += b - '0'; // Convert character to integer and add to count
        }
        return c; // Return the count of devices
    }

    // Function to calculate the number of beams in the bank
    int numberOfBeams(vector<string>& bank) 
    {
        vector<int> devices; // Vector to store the count of devices in each row

        // Iterate through each row in the bank
        for(auto row : bank)
        {
            devices.push_back(countDevices(row)); // Count devices in the current row and add to devices vector
        }   

        int beams = 0; // Initialize the total number of beams

        // Iterate through the devices vector
        for(int i = 0; i < devices.size(); i++)
        {
            int j = i + 1; // Initialize index j to the next row
            // Continue iterating until the end of the devices vector
            while(j < devices.size())
            {
                // Multiply the count of devices in the current row with the count of devices in the next row
                beams += devices[i] * devices[j];
                // If the count of devices in the next row is 0, increment j to skip consecutive 0s
                if(devices[j] == 0)
                {
                    j++;
                }
                else // If the count of devices in the next row is not 0, exit the loop
                {
                    break;
                }
            }
        }
        return beams; // Return the total number of beams
    }



/*
For example:
If b is '0', then b - '0' equals 0.
If b is '1', then b - '0' equals 1.
If b is '2', then b - '0' equals 2.   */






    // 2.******* Using Java *******   

    public int countDevices(String binary)
    {
        int count = 0;
        for(char b : binary.toCharArray())
        {
            count += b - '0';
        }

        return count;
    }

    public int numberOfBeams(String[] bank) 
    {
        List<Integer> devices = new ArrayList<>();

        for(String row : bank)
        {
            devices.add(countDevices(row));
        }

        int beams = 0;

        for(int i=0;i<devices.size();i++)
        {
            int j = i + 1;
            while(j < devices.size())
            {
                beams += devices.get(i) * devices.get(j);

                if(devices.get(j) == 0)
                {
                    j++;
                }
                else 
                {
                    break;
                }
            }
        }

        return beams;
    }
