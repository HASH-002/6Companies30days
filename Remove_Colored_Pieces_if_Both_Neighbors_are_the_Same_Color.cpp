class Solution {
   public:
    bool winnerOfGame(string s) {
        int i = 0, a = 0, b = 0;
        for (int i = 1; i < s.length() - 1; i++)
            if (s[i] == s[i - 1] && s[i] == s[i + 1])
                s[i] == 'A' ? a++ : b++;

        return a > b;
    }
};