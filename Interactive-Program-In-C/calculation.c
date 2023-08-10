// calculation.c

#include <stdio.h>

int main()
{
	char mathOperator;
	double num1, num2, result;

	printf("Entrez un opérateur (+, -, *, /): ");
	scanf("%c", &mathOperator);

	printf("Entrez les deux nombres à calculer: ");
	scanf("%lf %lf", &num1, &num2);

	switch (mathOperator)
	{
	  case '+':
		result = num1 + num2;
		break;
	  case '-':
		result = num1 - num2;
		break;
	  case '*':
		result = num1 * num2;
		break;
	  case '/':
		result = num1 / num2;
		break;
	  default:
		printf("L'opérateur n'est pas valide\n.");
		break;
	}

	printf("Le résultat de %.2lf %c %.2lf est %.2lf\n", num1, mathOperator, num2, result);

	return 0;
}
