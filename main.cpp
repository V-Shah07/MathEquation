#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include "StacksQueues.h"
#pragma warning(disable:4996)
#define TOP ((value*)(operators.getTail()->token))->Operator

//functions in here since idk how to do another header with library
bool isOperator(char c)
{
	switch (c) //more organized than if else
	{
	case '+': case '-': case '/': case '*': case '(': case ')': case '^': case '%':
		return true;
		break;
	}
	return false;
}
bool listEmpty(Stack l)
{
	if ((l.getHead() == NULL) || (l.getTail() == NULL))
	{
		return true;
	}
	return false;
}
bool listEmpty(Queue l)
{
	if ((l.getHead() == NULL) || (l.getTail() == NULL))
	{
		return true;
	}
	return false;
}

double evalExp(double num1, double num2, char operand)
{
	double ans = 0;
	switch (operand)
	{
	case '+':
		ans = num1 + num2;
		break;
	case '-':
		ans = num1 - num2;
		break;
	case '*':
		ans = num1 * num2;
		break;
	case '/':
		ans = num1 / num2;
		break;
	case '^':
		ans = pow(num1, num2);
		break;
	case '%':
		ans = (int)num1 % (int)num2;
		break;
	}

	return ans;
}
struct value
{
	bool isNum;
	double num;
	char Operator;
};

node* pushValue(Stack* s, value val)
{
	value* x = (value*)calloc(1, sizeof(value));
	*x = val;
	return (*s).push(x);
}

int main()
{ 
	value expression[30] = { 0 };
	printf("Enter the expression: ");

	char rankings[256];
	char plus = '+', minus = '-', multiply = '*', divide = '/', mod = '%', exp = '^';
	rankings[plus] = rankings[minus] = 1;
	rankings[multiply] = rankings[divide] = rankings[mod] = 2;
	rankings[exp] = 3;

	//gets input and clears spaces
	char ch;
	int i = 0;
	while ((ch = getchar()) != '\n')
	{
		if (ch == ' ')
			continue;
		else if (isdigit(ch))
		{
			ungetc(ch, stdin);
			expression[i].isNum = true;
			scanf("%lf", &expression[i].num);
		}
		else
		{
			expression[i].isNum = false;
			expression[i].Operator = ch;
		}
		++i;
	}
	int expLen = i;

	Queue postfix(sizeof(value));
	Stack operators(sizeof(value));

	//-------------------------Make postfix expression------------------------\\

	node* temp;
	for (int i = 0; i < expLen; ++i)
	{
		//digit means to add it to the postfix queue
		if (expression[i].isNum)
		{
			postfix.enqueue(&expression[i]);
		}

		//it is an operator
		else
		{
			// close parenthesis
			if (expression[i].Operator == ')')
			{
				//pop everything off the stack, enqueue onto the queue, till it you find open parentheses
				while (((value*)((temp = operators.pop())->token))->Operator != '(')
				{
					if (listEmpty(postfix))
					{
						printf("ERROR UNCLOSED \"(\" OR \")\"!!");
						exit(-1);
					}
					postfix.enqueue(temp->token);
				}

			}
			else //non ')' operator
			{
				//order of the operator on stack is higher than the order of the current operator, then pop that off and enqueue into postfix

				char curOperator = expression[i].Operator;
				while ((operators.getTail() != NULL) && (rankings[TOP] >= rankings[curOperator]) && (TOP != '(') && (curOperator != '('))
				{
					temp = operators.pop();
					postfix.enqueue(temp->token);
				}
				operators.push(&expression[i]);
			}
		}
	}
	//pop remaining operators off the stack
	while (listEmpty(operators) != true)
	{
		temp = operators.pop();
		postfix.enqueue(temp->token);
	}

	//------------------------Evaluate postfix expression-----------------------
	value model;
	Stack numbers(sizeof(value));
	double op1;
	double op2;
	for (node* mover = postfix.getHead(); mover != NULL; mover = mover->next)
	{
		if (((value*)(mover->token))->isNum)
		{
			numbers.push(mover->token);
		}
		else //operator
		{
			op2 = ((value*)(numbers.pop()->token))->num;
			op1 = ((value*)(numbers.pop()->token))->num;

			model.isNum = true;
			model.num = evalExp(op1, op2, ((value*)(mover->token))->Operator);
			pushValue(&numbers, model);
		}

		postfix.dequeue();
	}

	printf("\n\n%lf\n\n", ((value*)(numbers.getHead()->token))->num);
	
}
