#include"Calculator.h"
int main()
{
	  char stroka1[255] = "((3.36+2.549)/5.03+(3+4*(5-2)-1)/2)^0.5";
    char stroka2[255] = "3.5+2*5";
    char stroka9[255] = "(3+2)*5";
    char stroka3[255] = "(3+4*(5-2)-1)/2";
    char stroka4[255] = "(3+2)/5 + (3+4*(5-2)-1)/2";
    char stroka5[255] = "16.8/((3+2)/5 +(3+4*(5-2)-1)/2)";
    char stroka6[255] = "(64/32)+78-(20/4)+(2*(11-6))+45+2/2";
    char stroka7[255] = "(3+5)^2-60-2^3";
    char stroka8[255] = "((3+2)/5 + (3+4*(5-2)-1)/2)^0.5";
    char stroka10[255]="3*((1+3)*2-((2-1)*(4+2)-2)/2)/4";

    cout << stroka10 << "=" << Calculator::calculate(stroka10) << endl;
   cout << stroka1 << "=" << Calculator::calculate(stroka1) << endl;
    cout << stroka2 << "=" << Calculator::calculate(stroka2) << endl;
    cout << stroka9 << "=" << Calculator::calculate(stroka9) << endl;
    cout << stroka3 << "=" << Calculator::calculate(stroka3) << endl;
    cout << stroka4 << "=" << Calculator::calculate(stroka4) << endl;
    cout << stroka5 << "=" << Calculator::calculate(stroka5) << endl;
    cout << stroka6 << "=" << Calculator::calculate(stroka6) << endl;
    cout << stroka7 << "=" << Calculator::calculate(stroka7) << endl;
    cout << stroka8 << "=" << Calculator::calculate(stroka8);
	cout << endl;
	getchar();
	getchar();
}
