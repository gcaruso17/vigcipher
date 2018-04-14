#include <string>
using namespace std;

class VigEncrypter {
    private:
      string plaintext;
      string key;
      int charToInt(char c);
      char intToChar(int i);
      string extendKey(string key, int length);
    public:
        VigEncrypter(string p, string k);
        string encrypt();
};
