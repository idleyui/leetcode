class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
            sort(people.begin(), people.end());
    int count = 0, i = 0, j = people.size() - 1;
    while (i < j) {
        if (people[i] >= limit) {
            count += people.size();
            break;
        } else if (people[j] >= limit || (people[i] + people[j]) > limit) {
            j--;
        } else {
            i++;
            j--;
        }
        count += 1;
    }
    return i == j ? count + 1 : count;
    }
};