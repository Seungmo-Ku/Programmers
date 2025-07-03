#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int deliverIdx = n - 1;
    int pickupIdx = n - 1;

    while (deliverIdx >= 0 || pickupIdx >= 0) {
        // 배달/수거해야 할 가장 먼 위치 찾기
        while (deliverIdx >= 0 && deliveries[deliverIdx] == 0) deliverIdx--;
        while (pickupIdx >= 0 && pickups[pickupIdx] == 0) pickupIdx--;

        if (deliverIdx < 0 && pickupIdx < 0) break;

        int dist = max(deliverIdx, pickupIdx) + 1; // 거리
        answer += dist * 2;

        // 배달 처리
        int capLeft = cap;
        for (int i = deliverIdx; i >= 0 && capLeft > 0; --i) {
            int d = min(deliveries[i], capLeft);
            deliveries[i] -= d;
            capLeft -= d;
        }

        // 수거 처리
        capLeft = cap;
        for (int i = pickupIdx; i >= 0 && capLeft > 0; --i) {
            int p = min(pickups[i], capLeft);
            pickups[i] -= p;
            capLeft -= p;
        }
    }

    return answer;
}