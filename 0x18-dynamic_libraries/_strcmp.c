#include "main.h"

/**
 * _strcmp - compares 2 string
 * @s1: string 1
 * @s2: string 2
 * Return: 0 if s2 and s1 are equal, -1 otherwise
 */ 

int _strcmp(char *s1, char *s2)
{       
        int count = 0;
        
        while(s1[count] != '\0' && s2[count] != '\0')
        {       
                if(s1[count] != s2[count])
                        return(s1[count] - s2[count]);
                count++;
        }
	return(0);
}
