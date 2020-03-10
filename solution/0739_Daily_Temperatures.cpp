#include "alg.h"

vector<int> dailyTemperatures(vector<int> &T) {
    vector<int> min_step(T.size(), 0);
    for (int i = T.size() - 2; i >= 0; i--) {
        if (T[i] < T[i + 1]) min_step[i] = 1;
        else {
            int j = i + 1 + min_step[i + 1];
            for (; min_step[j] > 0 && T[i] >= T[j]; j += min_step[j]);
            min_step[i] = T[j] > T[i] ? (j - i) : 0;
        }
    }
    return min_step;
}

vector<int> dailyTemperatures_optim(vector<int> &T) {
    vector<int> min_step(T.size(), 1);
    min_step[T.size() - 1] = 0;
    for (int i = T.size() - 2; i >= 0; i--) {
        int j = i + min_step[i];
        for (; min_step[j] > 0 && T[i] >= T[j]; j += min_step[j]);
        min_step[i] = T[j] > T[i] ? (j - i) : 0;
    }
    return min_step;
}

int main() {

}