#include "string.h"
#include <stdlib.h>

int my_strlen(char *str) {
	int i=0;
	while(str[i])
		i++;
	return i;
}

int my_strcmp(char *str1, char *str2) {
	int i=0;
	int j=0;

	while(str1[i]!='\0' && str2[j]!='\0') {
		if(str1[i]<str2[j])
			return -1;
		if(str1[i]>str2[j])
			return 1;
		i++;
		j++;
	}
	if(str1[i]!='\0')
		return 1;
	if(str2[j]!='\0')
		return -1;
	return 0;
}

int trim(char *str) {
	int i;
	for(i=0; i<MAX_SIZE; i++) {
		if(str[i]=='\n') {
			str[i] = '\0';
			return 0;
		}
	}
	return -1;
}

char all_unique(char *str) {
	int i, j;
	int len = my_strlen(str);

	for(i=0; i<len-1; i++) {
		for(j=i+1; j<len; j++) {
			if(str[i]==str[j])
				return str[i];
		}
	}
	return '\0';
}

int indexOf(char *str, char c) {
	int i=0;
	while(str[i]) {
		if(str[i]==c)
			return i;
		i++;
	}
	return -1;
}

void reverse(char *str) {
	int i;
	int len = my_strlen(str);
	for(i=0; i<len/2; i++) {
		str[i] = str[i] ^ str[len-i-1];
		str[len-i-1] = str[i] ^ str[len-i-1];
		str[i] = str[i] ^ str[len-i-1];
	}
	return;
}

int isSubstring(char *str, char *substr) {
	int pos, i, j;
	int len = my_strlen(str);
	int subLen = my_strlen(substr);
	if(subLen==0)
		return 0;
	for(pos=0; pos<len-subLen+1; pos++) {
		i=pos;
		j=0;
		while(str[i] && substr[j] && str[i]==substr[j]) {
			i++;
			j++;
		}
		if(substr[j]=='\0')
			return pos;
	}
	return -1;
}

int my_atoi(char *str) {
	int ret = 0;
	int i=0;
	int sign = 1;
	if(str[i]=='-') {
		sign = -1;
		i++;
	}
	while(str[i]) {
		if(str[i]<0x30 || str[i]>0x39)
			return 0;
		ret = ret*10 + (str[i]-'0');
		i++;
	}
	return ret*sign;
}

void toUpper(char *str) {
	int i=0;
	while(str[i]) {
		if(str[i]>=97 && str[i]<=124)
			str[i] -= 32;
		i++;
	}
}

void toLower(char *str) {
	int i=0;
	while(str[i]) {
		if(str[i]>=65 && str[i]<=92)
			str[i] += 32;
		i++;
	}
}

char* my_strcpy(char *str) {
	int i;
	int len = my_strlen(str);
	char *newStr = (char*)calloc(len+1,sizeof(char));

	for(i=0; i<len; i++) {
		newStr[i] = str[i];
	}
	return newStr;
}
