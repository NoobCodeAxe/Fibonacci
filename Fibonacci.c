#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "Fibonacci.h"


/*
	Name: William Francois
	ID: U0000001232
*/

HugeInteger * hugeAdd(HugeInteger * p, HugeInteger * q)
{
	int length;
	int qBig = 0;
	int pBig = 0;
	int pLength = 0;
	int qLength = 0;
	int i = 0;
	HugeInteger *addResult = malloc(sizeof(HugeInteger));

	//If NULL return NULL
	if (p == NULL || q == NULL) {
		return NULL;
	}
		

	
	
	if (p->length > q->length) {
		length = p->length;
		pBig = 1;
	}
	else if (p->length == q->length) {
		length = p->length;
		pBig = 1;
	}
	else {
		length = q->length;
		qBig = 1;
	}
	addResult->length = length;
	 //saftey
	addResult->digits = malloc(sizeof(int) * (length+6));
	//actual addition
	

	for (i; i <= length + 1; i++) {          //clears the list
		addResult->digits[i] = 0;
	}

	for (int j = 0; j < length; j++) {
		if (pBig == 1) {
			if (j >= q->length) {
				addResult->digits[j] += p->digits[j];
			}
			else {
				if (p->digits[j] + q->digits[j] + addResult->digits[j] >= 10) {
					if (j + 1 == length) {
						addResult->length += 1;
					}
					int num = j + 1;
					int add = p->digits[j] + q->digits[j];
					add -= 10;
					if ((addResult->digits[num] += 1) == 10) {
						addResult->digits[num] = 0;
						addResult->digits[num+1] += 1;
					}
					
					if ((addResult->digits[j] += add) == 10) {
						addResult->digits[j] = 0;
						addResult->digits[j + 1] += 1;
					}
					
				}
				else {
				
					int add = 0;
					add = p->digits[j] + q->digits[j];
					if ((addResult->digits[j] += add) >= 10) {
						if (j + 1 == length) {
							addResult->length += 1;
						}
						addResult->digits[j] = 0;
						addResult->digits[j + 1] += 1;
					}
				}
			}
		}
		else {
			if (j >= q->length) {
				addResult->digits[j] += q->digits[j];
			}
			else {
				if (p->digits[j] + q->digits[j] + addResult->digits[j] >= 10) {
					if (j + 1 == length) {
						addResult->length += 1;
					}
					int num = j + 1;
					int add = p->digits[j] + q->digits[j];
					add -= 10;
					if ((addResult->digits[num] += 1) == 10) {
						addResult->digits[num] = 0;
						addResult->digits[num + 1] += 1;
					}

					if ((addResult->digits[j] += add) == 10) {
						addResult->digits[j] = 0;
						addResult->digits[j + 1] += 1;
					}

				}
				else {

					int add = 0;
					add = p->digits[j] + q->digits[j];
					if ((addResult->digits[j] += add) >= 10) {
						if (j + 1 == length) {
							addResult->length += 1;
						}
						addResult->digits[j] = 0;
						addResult->digits[j + 1] += 1;
					}
				}
			}
		}
	}
	
	return addResult;
}

HugeInteger * hugeDestroyer(HugeInteger * p)
{
	
	if (p != NULL) {
		if (p->digits != NULL) {
			free(p->digits);
		}

		free(p);
	}
	
	return NULL;
}

HugeInteger * parseString(char * str)
{
	int length = 0;
	int size = 0;
	if (str == NULL) {
		return NULL;
	}

	HugeInteger *parsed = malloc(sizeof(HugeInteger));
	 length = strlen(str);
	parsed->length = length;
	
	if (length > 0) {
		parsed->digits = malloc(sizeof(int) * length);
		size = length;
		for (int i = 0; i < size; i++) {
			length--;
			parsed->digits[i] = str[length] - '0';
		}
	}
	else {
		parsed->digits = malloc(sizeof(int));
		parsed->digits[0] = 0;
	}

	if (parsed == NULL || parsed->digits == NULL ) {
		return NULL;
	}

	return parsed;
}

HugeInteger * parseInt(unsigned int n)
{
	int i = 0;
	int length;

	if (n == NULL &&n != 0) {
		return NULL;
	}

	HugeInteger *parsedNum = malloc(sizeof(HugeInteger));
	
	if (n > 10) {
		length = (int)(log10(n) + 1);
	}
	else {
		length = 1;
	}
	
	parsedNum->length = length;
	parsedNum->digits = malloc(sizeof(int) * length);
	
	
	if (n > 10) {
		while (n > 0) {
			parsedNum->digits[i] = n % 10;
			n = n / 10;
			i++;
		}
	}
	else {
		parsedNum->digits[i] = n;
	}

	if (parsedNum == NULL || parsedNum->digits == NULL) {
		return NULL;
	}
	return parsedNum;
}

unsigned int * toUnsignedInt(HugeInteger * p)                
{
	unsigned int* dynamicUInt = NULL;
	unsigned int num = 0;

	if (p == NULL) {
		return NULL;
	}
	if (p->length > 10) {
		return NULL;
	}
	//convert p-> to number
	
	// get num back from string
	for (int i = 0; i < p->length; i++) {
		if (i == 0) {
			num+= p->digits[i];
		}
		else {
			num += ((pow(10, i)) * p->digits[i]);
		}
		
	}
	if (num > UINT_MAX) {
		return NULL;
	}
	//comparing

	 dynamicUInt = malloc(sizeof(unsigned int));               //have to dynamically allocate
	dynamicUInt[0] = num;
	
	
	return dynamicUInt;
}

HugeInteger * fib(int n)
{
	//base case
	HugeInteger *fibNum = malloc(sizeof(HugeInteger));
	HugeInteger *fibZero = parseInt(0);
	HugeInteger *fibOne = parseInt(1);
	HugeInteger *temp = NULL;
	HugeInteger *temp2 = NULL;
	HugeInteger *temp3 = NULL;


	if (n == 0) {
		return fibZero;
	}
	else if (n == 1) {
		return fibOne;
	}

	 temp2 = fibZero;
	 temp3 = fibOne;

	for (int i = 2; i <= n; i++) {
		temp = hugeAdd(temp2, temp3);
		free(temp2->digits);
		free(temp2);
		temp2 = temp3;
		temp3 = temp;
		
	}


	return temp3;
}

double difficultyRating(void)
{
	return 3.0;
}

double hoursSpent(void)
{
	return 7.0;
}
