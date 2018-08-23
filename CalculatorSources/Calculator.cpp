#include"Calculator.h"
double Calculator::calculate(const char* s)
{
	char strochka[255];
	Stack<char> operations;
	int i = 0;
	while (*s)
	{
		while (!isCorrect(*s))s++;
		if (isdigit(*s))
		{
			while (*s == '.' || isdigit(*s))
			{
				strochka[i] = *s;
				i++;
				s++;
			}
			strochka[i] = ' ';
			i++;
			if (!operations.isEmpty())
			{
				if (*s != '^'&&*s != '*'&&*s != '/')
				{
					if (operations.popReturn() == '-')
					{
						strochka[i] = operations.pop();
						i++;
					}
				}

			}
		}
		else if (*s == ')')
		{

			while (operations.popReturn() != '(')
			{
				strochka[i] = operations.pop();
				i++;
			}
			s++;
			if (*s == '^')
			{
				operations.push(*s);
				s++;
				if (isdigit(*s))
				{
					while (*s == '.' || isdigit(*s))
					{
						strochka[i] = *s;
						i++;
						s++;
					}
				}
				strochka[i] = operations.pop();
				i++;
			}
            if (*s == '/')
            {
                operations.push(*s);
                s++;
                if (isdigit(*s))
                {
                    while (*s == '.' || isdigit(*s))
                    {
                        strochka[i] = *s;
                        i++;
                        s++;
                    }
                }
                strochka[i] = operations.pop();
                i++;
            }
            if (*s == '*')
            {
                operations.push(*s);
                s++;
                if (isdigit(*s))
                {
                    while (*s == '.' || isdigit(*s))
                    {
                        strochka[i] = *s;
                        i++;
                        s++;
                    }
                }
                strochka[i] = operations.pop();
                i++;
            }
			operations.pop();
			if (!operations.isEmpty())
			{
				if (operations.popReturn() == '*' || operations.popReturn() == '/' || operations.popReturn() == '-')
				{
					strochka[i] = operations.pop();
					i++;
				}
			}

			strochka[i] = ' ';
			i++;
		}
		else if (*s == '(')
		{
			operations.push(*s);
			s++;
		}
		else if (*s == '*' || *s == '/' || *s == '^')
		{
			operations.push(*s);
			s++;
		}
		else if (*s == '+' || *s == '-')
		{
			char op;
			if (!operations.isEmpty())
			{
				if (operations.popReturn() == '*' || operations.popReturn() == '/' || operations.popReturn() == '^')
				{
					while (!operations.isEmpty())
					{
						if (operations.popReturn() == '*' || operations.popReturn() == '/' || operations.popReturn() == '^')
						{
							strochka[i] = operations.pop();
							i++;
						}
						else break;
					}
					operations.push(*s);
					s++;
				}
				else
				{
					operations.push(*s);
					s++;
				}
			}
			else
			{
				operations.push(*s);
				s++;
			}
		}
	}
	while (!operations.isEmpty())
	{

		strochka[i] = operations.pop();
		i++;
	}
	if (strochka[i - 1] == ' ')
		strochka[i - 1] = '\0';
	else strochka[i] = '\0';
	cout << endl;
	return postFix(strochka);
}
double Calculator::postFix(const char* s)
{
	double a = 0;
	double b = 0;
	Stack<double> numbers;
	while (*s)
	{
		while (!isCorrect(*s))s++;
		if (isdigit(*s))
		{
			double d = atof(s);
			numbers.push(d);
			while (*s == '.' || isdigit(*s))s++;
		}
		else if (*s == '+')
		{
			b = numbers.pop();
			a = numbers.pop();
			numbers.push(a + b);
			s++;

		}
		else if (*s == '-')
		{
			b = numbers.pop();
			a = numbers.pop();
			numbers.push(a - b);
			s++;
		}
		else if (*s == '*')
		{
			b = numbers.pop();
			a = numbers.pop();
			numbers.push(a * b);
			s++;
		}
		else if (*s == '/')
		{
			b = numbers.pop();
			a = numbers.pop();
			numbers.push(a / b);
			s++;
		}
		else if (*s == '^')
		{
			b = numbers.pop();
			a = numbers.pop();
			numbers.push(pow(a, b));
			s++;
		}
	}
	
	return numbers.pop();
}
bool Calculator::isCorrect(const char s)
{
	return isdigit(s) || s == '.' ||
		s == '+' || s == '-' || s == '*' ||
		s == '/' || s == '^' || s == '(' ||
		s == ')';
}