char* removeOuterParentheses(char* s) {
    int n = strlen(s);
    int k = 0; //vị trí;
    int depth = 0;
    char* result = malloc((n+1)*sizeof(char));
    for(int i = 0;i < n; i++){
        if(s[i] == '('){
            if(depth > 0){
                result[k++] = s[i];
            }
            depth++;
        }
        else{
            depth--;
            if(depth > 0){
                result[k++] = s[i];
            }
            
        }
    }
    result[k] = '\0';
    return result;
}