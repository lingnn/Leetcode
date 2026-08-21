int findMinDifference(char** timePoints, int timePointsSize) {
    bool seen[1440] = {false};

    for (int i = 0; i < timePointsSize; i++) {
        int hour = (timePoints[i][0] - '0') * 10
                 + (timePoints[i][1] - '0');
        int minute = (timePoints[i][3] - '0') * 10
                   + (timePoints[i][4] - '0');
        int time = hour * 60 + minute;
        if (seen[time]) {
            return 0;
        }
        seen[time] = true;
    }
    int prev = -1;
    int first = -1;
    int minDiff = 1440;

    for (int i = 0; i < 1440; i++) {
        if (seen[i]) {

            if (first == -1) {
                first = i;
            }

            if (prev != -1) {
                int diff = i - prev;

                if (diff < minDiff) {
                    minDiff = diff;
                }
            }

            prev = i;
        }
    }

    // Khoảng cách vòng tròn:
    // từ thời điểm cuối -> ngày hôm sau -> thời điểm đầu
    int circularDiff = 1440 - prev + first;

    if (circularDiff < minDiff) {
        minDiff = circularDiff;
    }

    return minDiff;
}