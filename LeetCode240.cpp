/*************************************************************************
	> File Name: LeetCode240.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月11日 星期三 21时36分27秒
 ************************************************************************/
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int row = matrixRowSize - 1, col = 0;
    int flag = 0;
    while(row >= 0 && col < matrixColSize) {
        if(matrix[row][col] == target) {
            flag = 1;
            break;
        }else if(matrix[row][col] < target) {
            col++;
        }else {
            row--;
        }

    }
    return flag;
}
