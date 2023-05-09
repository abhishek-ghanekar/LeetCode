class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        int startingRow = 0;
        int startingCol = 0;
        
        int endingRow = matrix.size() - 1;
        int endingCol = matrix[0].size() - 1;
        int count = 0;
        int total = matrix.size() * matrix[0].size();

        while(count < total) {
            //traverse the first row
            for(int i=startingCol;count < total && i <= endingCol ;i++) {
                output.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;
            //traverse the last column
            for(int i=startingRow;count < total && i <= endingRow ; i++) {
                output.push_back(matrix[i][endingCol]);
                count++;
            }//check agauibn
            endingCol--;
            //traversing the last row
            for(int i = endingCol; count < total && i >= startingCol; i--) {
                output.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
            //traversing the first column
            for(int i = endingRow ; count < total && i >= startingRow; i-- ) {
                output.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }
        return output;
    }
};