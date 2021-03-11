class Solution {
public:
    string reverseOnlyLetters(string S) {

        string holder;
        for (int i = 0; i < S.size(); i++)
        {
            if ((S[i] >= 65 && S[i] <= 90) || (S[i] >= 97 && S[i] <= 122))
            {
                holder += S[i];
            }

        }

        int j = holder.size() - 1;

        for (int i = 0; i < S.size(); i++)
        {
            if ((S[i] >= 65 && S[i] <= 90) || (S[i] >= 97 && S[i] <= 122))
            {
                S[i] = holder[j];
                j--;
            }
        }


        return S;
    }
};
