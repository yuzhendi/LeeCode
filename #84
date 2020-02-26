
int largestRectangleArea(int* heights, int heightsSize){
    int top = -1;
    int *stack = (int *)malloc(sizeof(int) * heightsSize);
    int *left = (int *)malloc(sizeof(int) * heightsSize);
    int *right = (int *)malloc(sizeof(int) * heightsSize);
    for (int i = 0; i < heightsSize; i++) {
        while (top != -1 && heights[stack[top]] >= heights[i]) --top;//按照升序进站
        left[i] = (top == -1 ? i + 1 : i - stack[top]);//记录当前节点到左侧矩形的宽度
        stack[++top] = i;
    }
    top = -1;
    for (int i = heightsSize - 1; i >= 0; i--) {
        while (top != -1 && heights[stack[top]] >= heights[i]) --top;//从有到左升序入
        right[i] = (top == -1 ? heightsSize - i : stack[top] - i);//记录当前节点到右侧矩形的宽度
        stack[++top] = i;
    }
    int ans = 0;
    for (int i = 0; i < heightsSize; i++) {
        ans = fmax(ans, (left[i] + right[i] - 1) * heights[i]);
    }
    free(stack);
    free(left);
    free(right);
    return ans;
}
