// Leet-Code : Q.No => 79 => Word Search => 3rd April 2024 


    //   BackTracking 


    // 1.******* Using C++ *******


    // Helper function for backtracking
    bool backTrack(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int i, int j, int index) {
        // Base case: if the entire word is found, return true
        if (index == word.length()) {
            return true;
        }

        // Check if current cell is out of bounds or not equal to the current character of the word
        // Also check if the cell has already been visited
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index] || visited[i][j]) {
            return false;
        }

        // Mark the current cell as visited
        visited[i][j] = true;

        // Explore neighboring cells recursively to find the next character of the word
        if (backTrack(board, word, visited, i, j - 1, index + 1) ||
            backTrack(board, word, visited, i, j + 1, index + 1) ||
            backTrack(board, word, visited, i - 1, j, index + 1) ||
            backTrack(board, word, visited, i + 1, j, index + 1)) {
            return true;
        }

        // If none of the neighboring cells lead to a solution, backtrack and mark the current cell as unvisited
        visited[i][j] = false;

        return false;
    }

    // Main function to check if the word exists on the board
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        // Create a boolean array to keep track of visited cells
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        bool result = false;

        // Iterate over each cell on the board
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // If the first character of the word matches the current cell, start backtracking
                if (board[i][j] == word[0]) {
                    result = backTrack(board, word, visited, i, j, 0);

                    // If the word is found, return true
                    if (result) {
                        return true;
                    }
                }
            }
        }

        // If the word is not found after checking all cells, return false
        return false;
    }





    // 2.******* Using Java ******* 


    // Helper function for backtracking
    public boolean backTrack(char [][]board, String word, boolean visited[][], int i, int j, int index)
    {
        // Base case: if the entire word is found, return true
        if(index == word.length())
        {
            return true;
        }

        // Check if current cell is out of bounds or not equal to the current character of the word
        // Also check if the cell has already been visited
        if(i < 0  || i >= board.length  || j < 0  || j >= board[0].length || board[i][j] != word.charAt(index) || visited[i][j])
        {
            return false;
        }

        // Mark the current cell as visited
        visited[i][j] = true;

        // Explore neighboring cells recursively to find the next character of the word
        if(backTrack(board, word, visited, i, j-1, index+1) || 
           backTrack(board, word, visited, i, j+1, index+1) ||
           backTrack(board, word, visited, i-1, j, index+1) ||
           backTrack(board, word, visited, i+1, j, index+1)) 
        {
            return true;
        }

        // If none of the neighboring cells lead to a solution, backtrack and mark the current cell as unvisited
        visited[i][j] = false;

        return false;
    }

    // Main function to check if the word exists on the board
    public boolean exist(char[][] board, String word) 
    {
        int row = board.length;
        int col = board[0].length;

        // Create a boolean array to keep track of visited cells
        boolean visited[][] = new boolean[row][col];
        boolean result = false;

        // Iterate over each cell on the board
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                // If the first character of the word matches the current cell, start backtracking
                if(board[i][j] == word.charAt(0))
                {
                    result = backTrack(board, word, visited, i , j , 0);

                    // If the word is found, return true
                    if(result)
                    {
                        return true;
                    }
                }
            }
        } 

        // If the word is not found after checking all cells, return false
        return false;   
    }