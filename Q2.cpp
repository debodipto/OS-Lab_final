#include <iostream>
using namespace std;

bool isInFrame(int frame[], int page, int size) {
    for (int i = 0; i < size; i++) {
        if (frame[i] == page)
            return true;
    }
    return false;
}

int main() {
    int pages[] = {0, 1, 5, 3, 5, 0, 2, 4, 7, 9, 0, 0, 3};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frameSize = 4;
    int frame[4];
    int front = 0;
    int count = 0;
    int hit = 0, miss = 0;

    for (int i = 0; i < n; i++) {
        if (isInFrame(frame, pages[i], count)) {
            hit++;
        } else {
            miss++;

            if (count < frameSize) {
                frame[count++] = pages[i];
            } else {
                frame[front] = pages[i];
                front = (front + 1) % frameSize;
            }
        }
    }

    cout << "Total Hits: " << hit << endl;
    cout << "Total Misses: " << miss << endl;

    return 0;
}
