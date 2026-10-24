class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int a = stoi(arriveAlice.substr(0, 2));
    int b = stoi(arriveAlice.substr(3, 2));
    int c = stoi(leaveAlice.substr(0, 2));
    int d = stoi(leaveAlice.substr(3, 2));
    int e = stoi(arriveBob.substr(0, 2));
    int f = stoi(arriveBob.substr(3, 2));
    int g = stoi(leaveBob.substr(0, 2));
    int h = stoi(leaveBob.substr(3, 2));
    for (int i = 0; i< a -1; i++) b+= month[i];
    for (int i = 0; i< c-1; i++) d+= month[i];
    for (int i = 0; i< e- 1; i++) f+= month[i];
    for (int i = 0; i<g- 1; i++)h+= month[i];
    int start = max(b, f);
    int end = min(d, h);
    if (start > end) return 0;
    return end - start + 1;
    }
};