#include <iostream>
#include <queue>
using namespace std;

struct Process {
    int id, at, bt, rt, ct;
};

int main() {
    int n = 6, quantum = 5;
    Process p[n] = {
        {1, 0, 7, 7, 0},
        {2, 1, 4, 4, 0},
        {3, 2, 15, 15, 0},
        {4, 3, 11, 11, 0},
        {5, 4, 20, 20, 0},
        {6, 4, 9, 9, 0}
    };

    queue<int> q;
    int time = 0, done = 0;
    bool inQueue[n] = {false};

    while (done < n) {

        for (int i = 0; i < n; i++)
            if (p[i].at <= time && !inQueue[i] && p[i].rt > 0) {
                q.push(i);
                inQueue[i] = true;
            }

        if (q.empty()) { time++; continue; }
        int i = q.front(); q.pop();
        int run = min(quantum, p[i].rt);
        p[i].rt -= run;
        time += run;

        for (int j = 0; j < n; j++)
            if (p[j].at <= time && !inQueue[j] && p[j].rt > 0) {
                q.push(j);
                inQueue[j] = true;
            }

        if (p[i].rt == 0) {
            p[i].ct = time;
            done++;
        } else {
            q.push(i);
        }
    }

    cout << "PID  CT   TAT  WT\n";
    for (int i = 0; i < n; i++) {
        int tat = p[i].ct - p[i].at;
        int wt = tat - p[i].bt;
        cout << "P" << p[i].id << "   " << p[i].ct << "   " << tat << "   " << wt << endl;
    }

    return 0;
}
