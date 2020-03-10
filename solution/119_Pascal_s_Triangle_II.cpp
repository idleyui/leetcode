#include "alg.h"

vector<int> getRow(int rowIndex) {
    vector<int> line(rowIndex + 1, 1);
    for (int i = 1; i <= rowIndex; i++) {
        for (int j = i - 1; j > 0; j--) {
            line[j] = line[j] + line[j - 1];
        }
    }
    return line;
}

int main() {

}