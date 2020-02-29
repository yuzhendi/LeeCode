typedef struct {
    int *data;
	int top, size;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *s = (MyStack *)malloc(sizeof(MyStack));
    s->data = (int *)malloc(sizeof(int) * 100);
    s->top = -1;
    s->size = 0;
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
  obj->top++;
  obj->data[obj->top] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
  if(obj->top < 0) return 0;
  int a = obj->data[obj->top];
  obj->top--;
  return a;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
  return obj->data[obj->top];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
  return obj->top == -1;
}

void myStackFree(MyStack* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
