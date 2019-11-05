#include "alg.h"

bool isPalindrome(string s) {
    int low = 0, high = s.size() - 1;
    while (low <= high) {
        if (!isalpha(s[low]) && !isdigit(s[low])) {
            low++;
        } else if (!isalpha(s[high]) && !isdigit(s[high])) {
            high--;
        } else if (tolower(s[low]) != tolower(s[high])) {
            return false;
        } else {
            low++;
            high--;
        }
    }
    return true;
}

int main() {

    cout << isalpha('c');
    cout << isalpha('0');
    cout << isalpha('.');
    cout << isalpha('C') << endl;
    cout << tolower('C');
    cout << tolower('c');
    cout << tolower('c');
}