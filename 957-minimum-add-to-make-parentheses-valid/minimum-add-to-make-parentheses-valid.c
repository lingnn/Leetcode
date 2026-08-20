int minAddToMakeValid(char* s) {
    int open = 0, close = 0;
    for(int i = 0;i < strlen(s);i ++){
        if(s[i] == '('){
            open++;
        }
        else if(s[i] == ')' && open >0){
            open--;
        }
        else
            close++;
    }
    return open + close;
}