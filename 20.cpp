/*************************************************************************
	> File Name: 20.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2020年02月27日 星期四 19时23分17秒
 ************************************************************************/

bool isValid(char * s){
    int len = strlen(s);
    if(len % 2 != 0) return false;
    char *stack  = (char *)malloc(sizeof(char) * len);
    int flag = 1, top = -1;
    while(s[0]) {
        switch(s[0]) {
        case  '(' :
        case '{' :
        case '[' : stack[++top] = s[0];break;
        case ')' : flag = (top != -1 && stack[top--] == '(' );break;
        case ']' : flag = (top != -1 && stack[top--] == '[');break;
        case '}' : flag = (top != -1 && stack[top--] == '{');break;
        }
        if(!flag) break;
        s++;
    }
    free(stack);
    return (flag && top == -1);
}
