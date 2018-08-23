#ifndef CALCULATOR_H
#define CALCULATOR_H
#include"Stack.h"
#include<iostream>
#include <cmath>
using namespace std;
class Calculator
{
public:
	static double calculate(const char* s);
private:
	static double postFix(const char* s);
	static bool isCorrect(const char s);
};

#endif;
