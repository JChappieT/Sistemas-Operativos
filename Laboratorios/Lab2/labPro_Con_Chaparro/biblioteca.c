#include "biblioteca.h"
void reverse_string(char *str) {
    int last, limit, first;
    char temp;
    last = strlen(str) - 1;
    limit = last/2;
    first = 0;
    
    while (first < last) {
       temp = str[first];
       str[first] = str[last];
       str[last] = temp;
       first++;
       last--;
    }
    return;
 }