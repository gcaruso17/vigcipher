#include <string>
using namespace std;

class Arguments {
    private:
        string message;
        string key;
        string answer;
    public:
        Arguments();
        string getMessage();
        string getKey();
        string getOperation();
};
