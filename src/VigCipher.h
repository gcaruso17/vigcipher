#include <string>
using namespace std;

class VigCipher {
    private:
      string plaintext;
      string key;
      int charToInt(char c);
      char intToChar(int i);
      int eucMod(int a, int b);
      string extendKey(string key, int length);
      string processText(string operation);
    public:
        VigCipher(string p, string k);
        string encrypt();
        string decrypt();
};
