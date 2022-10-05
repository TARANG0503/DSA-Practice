import java.io.Console;
import java.util.*;

public class SudokuSolver {
    public static void main(String args[]){
        String[][] board = {{"5","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."},{".","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},{"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},{".",".",".",".","8",".",".","7","9"}};
    System.out.println(sudoku(board));
    if (sudoku(board)){
     
        display(board);

    }else{
        System.out.println("cannot solve");
    }
    }
    static boolean sudoku(String[][] board){
        int n=board.length;
        int row=-1;
        int col=-1;
        boolean left=true;

        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if(board[i][j].equals(".")){
                    row=i;
                    col=j;
                    left=false;
                    break;
                }
             
            }
            if (left==false){
                break;
            }
        }
        if (left==true){
            return true;
        }

        for (int num=1;num<=9;num++){
            if (isSafe(board,row,col,num)){
                board[row][col]=String.valueOf(num);
                if (sudoku(board)){
                    return true;
                }
                else{
                    board[row][col]=".";
                }

            }

        }
        return false;

    }

    private static void display(String[][] board) {
        for(String[] row : board) {
            for(String num : row) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
    static boolean isSafe(String[][] board,int row,int col,int num){
        //checking row
        for (int i=0;i<board.length;i++){
            if (board[row][i].equals(String.valueOf(num))) return false;

        }
        //colum
        for (String[] nums:board ){
            if (nums[col].equals(String.valueOf(num))) return false;

        }
        //grid
        int sqr=(int)Math.sqrt(board.length);
        int rowStart=row-row%sqr;
        int colStart=col-col%sqr;
        for (int r=rowStart;r<rowStart+sqr;r++){
            for (int c=colStart;c<colStart+sqr;c++){
                if (board[r][c].equals(String.valueOf(num))) return false;
            }
        }
        return true;

    }
    
}
