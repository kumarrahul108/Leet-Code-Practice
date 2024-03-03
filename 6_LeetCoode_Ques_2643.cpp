
// Leet-Code : Q.No => 2643 => Row with Maximum Ones -> 3rd March 2024 


    // 1. Using C++


    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) 
    {
        vector<int> ans;        

        int one = -1;
        int row = -1;

        for(int i=0;i<mat.size();i++)
        {
            int count = 0;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j] == 1)
                {
                    count++;
                } 
            }
            /*
            row = count > one ? i : row;
            one = max(count,one);
            */
            if(count > one)
            {
                one = count;
                row = i;
            }
        } 

        ans.push_back(row);
        ans.push_back(one);

        return ans;      
    }



    // 2. Using Java 

    public int[] rowAndMaximumOnes(int[][] mat) 
    {
        int ans[] = new int[2];

        int row = -1;
        int one = -1;

        for(int i=0;i<mat.length;i++)
        {
            int count = 0;
            for(int j=0;j<mat[i].length;j++)
            {
                if(mat[i][j] == 1)
                {
                    count++;
                }
            }

            if(count > one)
            {
                one = count;
                row = i;
            }
        }

        ans[0] = row;
        ans[1] = one;

        return ans;
    }


