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
    virtual int GetPrecedence() = 0;

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

    virtual double GetValue() = 0;
    virtual int GetPrecedence() = 0;

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
    double GetValue() { return (lhs * pow(10, rhs)); }
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
    int precedence = 6;
} Sin;

class Cos : public UnaryOperator {
   public:
    Cos() = default;
    double GetValue() { return cos(rhs); }
    int GetPrecedence() { return this->precedence; }

   protected:
    int precedence = 6;
} Cos;

class Tan : public UnaryOperator {
   public:
    Tan() = default;
    double GetValue() { return tan(rhs); }
    int GetPrecedence() { return this->precedence; }

   protected:
    int precedence = 6;
} Tan;

class Factorial : public UnaryOperator {
   public:
    Factorial() = default;
    double GetValue() {
        double value = 1;
        for (int q = 2; q <= floor(rhs); ++q) {
            value *= q;
        }
        return value;
    }
    int GetPrecedence() { return this->precedence; }

   protected:
    int precedence = 10;
} Factorial;

class Square : public UnaryOperator {
   public:
    Square() = default;
    double GetValue() { return pow(rhs, 2); }
    int GetPrecedence() { return this->precedence; }

   protected:
    int precedence = 4;
} Square;

class Sqrt : public UnaryOperator {
   public:
    Sqrt() = default;
    double GetValue() { return pow(rhs, 0.5); }
    int GetPrecedence() { return this->precedence; }

   protected:
    int precedence = 3;
} Sqrt;

class Power2 : public UnaryOperator {
   public:
    Power2() = default;
    double GetValue() { return pow(2, rhs); }
    int GetPrecedence() { return this->precedence; }

   protected:
    int precedence = 3;
} Power2;

class Power10 : public UnaryOperator {
   public:
    Power10() = default;
    double GetValue() { return pow(10, rhs); }
    int GetPrecedence() { return this->precedence; }

   protected:
    int precedence = 3;
} Power10;

class Negate : public UnaryOperator {
   public:
    Negate() = default;
    double GetValue() { return -rhs; }
    int GetPrecedence() { return this->precedence; }

   protected:
    int precedence = 3;
}Negate;

#endif
