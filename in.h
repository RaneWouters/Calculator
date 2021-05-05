#include <iostream>
#include <vector>
using namespace std;

class In {
   public:
    In() = default;
    void Init();
    void CE() { this->target.erase(this->target.end() - 1); };
    void C() { this->target.clear(); };

    vector<string>& GetVec() { return this->target; }

   private:
    vector<string> target;
}In;

void In::Init() {
    string a;
    while(cin >> a) {
        if(a == "pi"){
            a = "3.141592653";
        }
        this->target.push_back(a);
    }
}
