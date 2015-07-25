#ifndef STRING_H_
#define STRING_H_

#define MAX_SIZE 100

int my_strlen(char *str);

int my_strcmp(char *str1, char *str2);

int trim(char *str);

char all_unique(char *str);

int indexOf(char *str, char c);

void reverse(char *str);

int isSubstring(char *str, char *substr);

int my_atoi(char *str);

void toUpper(char *str);

void toLower(char *str);

char* my_strcpy(char *str);

#endif
