#include "alg.h"




vector<double>
calcEquation(vector<pair<string, string>> equations, vector<double> &values, vector<pair<string, string>> queries) {
    unordered_map<pair<string, string>, double> pair2value;
    for (int i = 0; i < equations.size(); ++i) { pair2value[equations[i]] = values[i]; }

    unordered_map<string, vector<string>> neibor;
    for (auto &p: equations) {
        neibor[p.first].push_back(p.second);
    }

}

int main() {

}