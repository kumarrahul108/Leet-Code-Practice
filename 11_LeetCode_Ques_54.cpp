
// Leet-Code : Q.No => 54 => Spiral Matrix -> 5th March 2024 

    

    // 1. Using C++


    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> ans;

        int row = matrix.size();
        int col = matrix[0].size();

        int count  = 0;
        int totalElement = (row * col); 

        int startingRow = 0;
        int endingRow = row-1;
        int startingCol = 0;
        int endingCol = col-1;

        while(count < totalElement)
        {
            // starting row 
            for(int i=startingCol;i<=endingCol && count < totalElement;i++)
            {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++; 

            // ending column 
            for(int i=startingRow;i<=endingRow && count < totalElement;i++)
            {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;  

            //ending row 
            for(int i=endingCol;i>=startingCol && count < totalElement;i--)
            {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;

            // starting column 
            for(int i=endingRow;i>=startingRow  &&  count < totalElement;i--)
            {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }

        return ans;

    }




    // 2. Using Java 

    public List<Integer> spiralOrder(int[][] matrix) 
    {
        List<Integer> ans = new ArrayList<>(); 

        int row = matrix.length;
        int col = matrix[0].length;

        int count  = 0;
        int totalElement = (row * col); 

        int startingRow = 0;
        int endingRow = row-1;
        int startingCol = 0;
        int endingCol = col-1;

        while(count < totalElement)
        {
            // starting row 
            for(int i=startingCol;i<=endingCol && count < totalElement;i++)
            {
                ans.add(matrix[startingRow][i]);
                count++;
            }
            startingRow++; 

            // ending column 
            for(int i=startingRow;i<=endingRow && count < totalElement;i++)
            {
                ans.add(matrix[i][endingCol]);
                count++;
            }
            endingCol--;  

            //ending row 
            for(int i=endingCol;i>=startingCol && count < totalElement;i--)
            {
                ans.add(matrix[endingRow][i]);
                count++;
            }
            endingRow--;

            // starting column 
            for(int i=endingRow;i>=startingRow  &&  count < totalElement;i--)
            {
                ans.add(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }

        return ans; 
    }





  
