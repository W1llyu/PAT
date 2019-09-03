#include <iostream>
#include <string.h>
#define MAX 1050
using namespace std;

void gen_palindromic_num(char *str, char *dst) {
	int len = strlen(str);
	for (int i=0; i<len; i++) {
		dst[i] = str[len-i-1];
	}
	dst[len] = '\0';
}

void gen_sum(char *a, char *b) {
	int len = strlen(a), d = 0, tmp;
	for (int i=0; i<len; i++) {
		tmp = (b[i] - '0') + (b[len-1-i] - '0') + d;
		a[i] = (char)(tmp % 10 + '0');
		if (tmp >= 10) d = 1;
		else d = 0;
		if (i == len-1 && d > 0) a[i+1] = (char)(d+'0');
	}
	len = strlen(a);
	for (int i=0; i<len/2; i++) {
		char tmp = a[i];
		a[i] = a[len-i-1];
		a[len-i-1] = tmp;
	}
	a[len] = '\0';
}

char number[MAX] = {'\0'}, reverse[MAX] = {'\0'};
int main () {
	scanf("%s", number);
	gen_palindromic_num(number, reverse);
	for (int i=0; i<10; i++) {
		char tmp[MAX] = {'\0'};
		if (strcmp(number, reverse) == 0) {
			break;
		} else {
			printf("%s + %s = ", number, reverse);
			gen_sum(number, reverse);
			printf("%s\n", number);
			gen_palindromic_num(number, reverse);
		}
	}
	if (strcmp(number, reverse) == 0) printf("%s is a palindromic number.\n", number);
	else printf("Not found in 10 iterations.\n");
	return 0;
}

