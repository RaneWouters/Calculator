#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include "in.h"
#include "operator.h"
#include "reversepolish.h"
using namespace std;

map<string, class Operator&> OperatorFactory::ms_register;
constexpr double PI = 3.141592653;

int main() {
    OperatorInit(OperatorFactory);

    In.Init();

    //    temp1.push_back("sin");
    //    temp1.push_back("3");

    //    class Operator* it = &OperatorFactory.Find("!");
    //    ((class UnaryOperator*)it)->SetRhs(5);
    //    cout << ((class BinaryOperator*)it)->GetRhs() << endl;
    //    cout << ((class BinaryOperator*)it)->GetValue() << endl;

    queue<string> target = RPInit(In.GetVec());
    queue<string> temp2 = target;

    while (!temp2.empty()) {
        cout << temp2.front() << ' ';
        temp2.pop();
    }
    cout << endl;

    cout << RPCalculate(target) << endl;

    //    for (auto it = temp1.begin(); it != temp1.end(); ++it) {
    //        cout << *it << OperatorFactory.Find(*it).GetPrecedence() << endl;
    //        cout << *it << endl;
    //    }

    return 0;
}
