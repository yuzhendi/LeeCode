/*************************************************************************
	> File Name: LeetCode994.cpp
	> Author:
	> Mail: 
	> Created Time: 2020年03月04日 星期三 20时52分14秒
 ************************************************************************/
typedef struct {
    int x;
    int y;
    int lev;
}Queue;
//BFS广度优先遍历
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int m = gridSize, n = gridColSize[0];
    int i, j;
    int x_shift[] = {-1, 1, 0, 0};
    int y_shift[] = {0, 0, -1, 1};

    Queue *Q = (Queue *)malloc(sizeof(Queue) * m * n);//存放腐烂橘子位置的队列（数组）
    int front = 0, rear = 0;
    int x, y, xx, yy, lev = 0;
    /*坏橘子如队列， lev 置零*/
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if(grid[i][j] == 2) {
                Q[rear].x = i;
                Q[rear].y = j;
                Q[rear++].lev = 0;
            }
        }
    }
    /* BFS广度优先遍历, 坏橘子出队列x/y, 与之相邻的好橘子进队列, 依次处理 */
    while(front != rear) {
        x = Q[front].x;
        y = Q[front].y;
        lev = Q[front++].lev;
        /*寻找好橘子*/
        for(i = 0; i < 4; i++) {//上下左右
            xx = x + x_shift[i];
            yy = y + y_shift[i];
            if(xx < 0 || xx >= m || yy < 0 || yy >=n || grid[xx][yy] != 1) {
                //越界
                continue;
            }
            //*将好橘子染坏*/
            grid[xx][yy] = 2;
            Q[rear].x = xx;
            Q[rear].y = yy;
            Q[rear++].lev = lev + 1;//分钟数为上一个的加 1
        }
    }
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if(grid[i][j] == 1) {
                return -1;//最后还存在好橘子
            }
        }
    }
    return lev;
}


