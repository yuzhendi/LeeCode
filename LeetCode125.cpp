/*************************************************************************
	> File Name: LeetCode125.cpp
	> Author:
	> Mail: 
	> Created Time: 2020年03月08日 星期日 21时43分42秒
 ************************************************************************/
bool is_num_abc(char *ch) {
    if(*ch >= '0'&&*ch <= '9') return true;
    else if(*ch >= 'a'&&*ch <= 'z') return true;
    else if(*ch >= 'A'&&*ch <= 'Z')
    {
        *ch = *ch + 32;
        return true;
    }
    else return false;
}

bool isPalindrome(char * s){
    if(s == NULL) return true;
    int head = 0, tail = 0;
    while(s[tail]) {
        tail++;
    }
    while(head < tail) {
        while(head < tail && !is_num_abc(&s[head])) head++;
        while(head <tail && !is_num_abc(&s[tail])) tail--;
        if(head < tail && s[head] != s[tail]) {
            return false;
        }
        head++;
        tail--;
    }
    return true;
}
