#include "string.h"

int my_strlen(char *str) {
	int i=0;
	while(str[i])
		i++;
	return i;
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

int reverse(char *str) {
	int i;
	int len = my_strlen(str);
	for(i=0; i<len/2; i++) {
		str[i] = str[i] ^ str[len-i-1];
		str[len-i-1] = str[i] ^ str[len-i-1];
		str[i] = str[i] ^ str[len-i-1];
	}
	return 0;
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
	while(str[i]) {
		ret = ret*10 + (str[i]-'0');
		i++;
	}
	return ret;
}
