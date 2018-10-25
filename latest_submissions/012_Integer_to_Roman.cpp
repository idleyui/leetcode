class Solution {
public:
    
    vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> symbol = {"M", "CM", "D", "CD", "C","XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string intToRoman(int num) {
        string roman = "";

        for (int i = 0; i < value.size() && num; ++i) {
            while(num >= value[i]){
                roman += symbol[i];
                num-=value[i];
            }
            // for(int j = 0; j < num/value[i];j++)roman += symbol[i];
            // if (num >= value[i]) num %= value[i];
        }

        return roman;
    }
};