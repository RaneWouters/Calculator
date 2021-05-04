#ifndef _OPERATOR_H_
#define _OPERATOR_H_

#include <math.h>
#include <cmath>
#include <iostream>
using namespace std;

class Operator {
   public:
    Operator() = default;
    virtual int GetOprand() = 0;
    virtual int GetPrecedence() = 0;
    virtual double GetValue() = 0;

   protected:
    int oprand;
    int precedence;
};

class BinaryOperator : public Operator {
   public:
    BinaryOperator() = default;

    double GetLhs() { return lhs; }
    double GetRhs() { return rhs; }

    void SetLhs(const double& x) { lhs = x; }
    void SetRhs(const double& x) { rhs = x; }

    int GetOprand() { return this->oprand; };

    virtual double GetValue() = 0;
    virtual int GetPrecedence() { return 0; };

   protected:
    double lhs;
    double rhs;
    int oprand = 2;
};

class UnaryOperator : public Operator {
   public:
    UnaryOperator() = default;

    double GetRhs() { return rhs; }

    void SetRhs(const double& x) { rhs = x; }

    int GetOprand() { return this->oprand; };

    virtual double GetValue() { return 0; };
    virtual int GetPrecedence() { return 0; };

   protected:
    double rhs;
    int oprand = 1;
};

//----------------binary operator----------------------//
//----------------binary operator----------------------//
//----------------binary operator----------------------//

class Plus : public BinaryOperator {
   public:
    Plus() = default;
    double GetValue() { return GetLhs() + GetRhs(); }
    int GetPrecedence() { return this->precedence; }

   protected:
    int precedence = 0;
} Plus;

class Minus : public BinaryOperator {
   public:
    Minus() = default;
    double GetValue() { return GetLhs() - GetRhs(); }
    int GetPrecedence() { return this->precedence; }

   protected:
    int precedence = 1;
} Minus;

class Times : public BinaryOperator {
   public:
    Times() = default;
    double GetValue() { return GetLhs() * GetRhs(); }
    int GetPrecedence() { return this->precedence; }

   protected:
    int precedence = 2;
} Times;

class Divide : public BinaryOperator {
   public:
    Divide() = default;
    double GetValue() { return GetLhs() / GetRhs(); }
    int GetPrecedence() { return this->precedence; }

   protected:
    int precedence = 2;
} Divide;

class Mod : public BinaryOperator {
   public:
    Mod() = default;
    double GetValue() { return (int)GetLhs() % (int)GetRhs(); }
    int GetPrecedence() { return this->precedence; }

   protected:
    int precedence = 2;
} Mod;

class Pow : public BinaryOperator {
   public:
    Pow() = default;
    double GetValue() { return pow(lhs, rhs); }
    int GetPrecedence() { return this->precedence; }

   protected:
    int precedence = 3;
} Pow;

class Exp : public BinaryOperator {
   public:
    Exp() = default;
    double GetValue() { return pow(lhs, rhs); }
    int GetPrecedence() { return this->precedence; }

   protected:
    int precedence = 3;
} Exp;

//----------------unary operator----------------------//
//----------------unary operator----------------------//
//----------------unary operator----------------------//

class Sin : public UnaryOperator {
   public:
    Sin() = default;
    double GetValue() { return sin(rhs); }
    int GetPrecedence() { return this->precedence; }

   protected:
    int precedence = 4;
} Sin;

class Cos : public UnaryOperator {
   public:
    Cos() = default;
    double GetValue() { return cos(rhs); }
    int GetPrecedence() { return this->precedence; }

   protected:
    int precedence = 4;
} Cos;

class Tan : public UnaryOperator {
   public:
    Tan() = default;
    double GetValue() { return tan(rhs); }
    int GetPrecedence() { return this->precedence; }

   protected:
    int precedence = 4;
} Tan;

#endif
