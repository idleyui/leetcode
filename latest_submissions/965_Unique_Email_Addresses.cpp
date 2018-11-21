class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniq_email;
        for(const string &s: emails){
            int pos = s.find_first_of('@');
            string name = s.substr(0, pos);
            int plus_pos = name.find_first_of('+');
            if (plus_pos != string::npos)   name = name.substr(0, plus_pos);
            name.erase(std::remove(name.begin(), name.end(), '.'), name.end());
            uniq_email.insert(name + s.substr(pos+1, s.size()));
        }
        return uniq_email.size();
    }
};