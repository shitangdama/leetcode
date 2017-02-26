public class Solution {
     // using O(m+n) is easy, to enable O(1), we have to use the space within the matrix   
    public void setZeroes(int[][] matrix) {
        if(matrix == null || matrix.length == 0)
            return;
        
        int rows = matrix.length;
        int cols = matrix[0].length;
        
        boolean empty_row0 = false;
        boolean empty_col0 = false;
        for(int i = 0; i < cols; i++){
            if(matrix[0][i] == 0){
                empty_row0 = true;
                break;
            }
        }
        
        for(int i = 0; i < rows; i++){
            if(matrix[i][0] == 0){
                empty_col0 = true;
                break;
            }
        }
        
        for(int i = 1; i < rows; i++) {
            for(int j =1; j<cols; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for(int i = 1; i<rows; i++) {
            for (int j=1; j< cols; j++) {
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }
      
        if(empty_row0){
            for(int i = 0; i < cols; i++){
                matrix[0][i] = 0;
            }           
        }
        
        if(empty_col0){
            for(int i = 0; i < rows; i++){
                matrix[i][0] = 0;
            }           
        }

    }
}