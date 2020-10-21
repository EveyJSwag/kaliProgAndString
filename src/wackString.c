#include "../lib/wackString.h"


void refStringArr(char *** strArr)
{
    const char* str1 = "I LOVE TONY";


    strArr = (char ***)malloc(100);
    *strArr = (char **)malloc(1000);

    for (int i = 0; i < 3; i++)
    {

        strArr[i]    = (char **)malloc(65535);
        *(strArr)[i] = (char *) malloc(65535);
        memcpy(*strArr[i], str1, strLen((char*)str1));

    }
}

unsigned int strLen(char* str)
{
    unsigned int length = 0;
    while(*str)
    {
        length++;
        str++;
    }
    
    return length;

}
