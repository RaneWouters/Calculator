#ifndef _CLASS_FACTORY_H_
#define _CLASS_FACTORY_H_

#include <map>
#include <memory>
#include <queue>
#include "operator.h"
using namespace std;

extern double RPCalculate(queue<string>& temp);

class OperatorFactory {
   public:
    OperatorFactory() = default;
    void Register(string, class Operator&);
    class Operator& Find(string);

   protected:
    static map<string, class Operator&> ms_register;
} OperatorFactory;

void OperatorFactory::Register(string temp, class Operator& opr) {
    this->ms_register.emplace(temp, opr);
}

class Operator& OperatorFactory::Find(string temp) {
    return this->ms_register.find(temp)->second;
}

void OperatorInit(class OperatorFactory& OperatorFactory) {
    OperatorFactory.Register("+", Plus);
    OperatorFactory.Register("-", Minus);
    OperatorFactory.Register("*", Times);
    OperatorFactory.Register("/", Divide);
    OperatorFactory.Register("^", Pow);
    OperatorFactory.Register("sin", Sin);
    OperatorFactory.Register("cos", Cos);
    OperatorFactory.Register("tan", Tan);
}

class MRegister {
   public:
    MRegister() = default;

    double MR() { return this->value; }
    void MC() { this->value = 0; }

    void MS(class queue<string>&);
    void MPlus(class queue<string>&);
    void MMinus(class queue<string>&);

   private:
    double value = 0;
} MRegister;

void MRegister::MS(queue<string>& temp) {
    this->value = RPCalculate(temp);
}
void MRegister::MPlus(queue<string>& temp) {
    this->value += RPCalculate(temp);
}
void MRegister::MMinus(queue<string>& temp) {
    this->value -= RPCalculate(temp);
}

#endif
