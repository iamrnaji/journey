class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {

        int rami = 0;
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < s.size(); j++)
            {
                if (s[i] == s[j] && &s[i] != &s[j])
                {
                    rami++;
                    int max = 0;
                    for (int k = i; k < j - 1; k++)
                    {
                        max++;
                        if (max > count)
                        {
                            count = max;
                        }
                    }
                }
            }
        }

        if (rami == 0)
        {
            return -1;
        }
        return count;
    }
};
