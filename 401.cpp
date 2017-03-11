#include <iostream>
#include <vector>
using namespace std;

int a[10] = {1,2,4,8,1,2,4,8,16,32};
int flag[10] = {1,1,1,1,1,1,1,1,1,1};

vector<string> result;

void traceback(int n, int hour, int minute, int k) {
    if (n == 0) {
        string rst = to_string(hour);
        if (minute < 10)
            rst += ":0" + to_string(minute);
        else
            rst += ":" + to_string(minute);
        result.push_back(rst);
        return;
    }
    for (int i=k; i<10; ++i) {
        if (flag[i] && i<4 && a[i]+hour<=11) {
            flag[i] = 0;
            traceback(n-1, hour+a[i], minute, i+1);
            flag[i] = 1;
        }
        if (flag[i] && i>=4 && minute+a[i]<=59) {
            flag[i] = 0;
            traceback(n-1, hour, minute+a[i], i+1);
            flag[i] = 1;
        }
    }
    return;
}

int main() {
    int n = 0;
    cin >> n;
    int hour = 0, minute = 0;
    traceback(n, hour, minute, 0);
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
