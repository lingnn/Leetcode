int minEatingSpeed(int* piles, int pilesSize, int h) {
    int maxPile = 0;
    for(int i = 0; i < pilesSize;i++){
        if (piles[i] > maxPile)
            maxPile = piles[i];
    }
    int left = 1;
    int right = maxPile;
    int ans = maxPile;
    while(left <= right){
        int mid = (left + right)/2;
        long long hour = 0;
        for(int i = 0;i < pilesSize;i++){
            hour += ceil((double)piles[i] / mid);
        }
        if (hour <= h) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}