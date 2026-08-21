int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    int total = 0;
    for(int i = 0 ;i < timeSeriesSize - 1;i ++){
        int diff = timeSeries[i + 1] - timeSeries[i];

        if (diff < duration) {
            total += diff;
        } else {
            total += duration;
        }
    }
    total += duration;
    return total;
}