class Solution {
public:

    string decodeCiphertext(string encodedText, int r) {
        int n = encodedText.size();
        string orignalText;
        for (int i = 0; i < n / r; i++) {
            for (int j = i; j < n; j += (n / r) + 1)
                orignalText += encodedText[j];
        }

        int idx = orignalText.size()-1;
        while(idx>=0 && orignalText[idx]==' ') idx--;

        orignalText.resize(idx+1);
        return orignalText;
    }
};