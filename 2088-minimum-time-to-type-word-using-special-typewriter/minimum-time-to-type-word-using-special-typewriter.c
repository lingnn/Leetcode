int minTimeToType(char* word) {
    int t = 0;
    int cur = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        int target = word[i] - 'a';

        int diff = abs(target - cur);
        int move = diff < 26 - diff ? diff : 26 - diff;
        t += move;
        t++;
        cur = target;
    }
    return t;
}