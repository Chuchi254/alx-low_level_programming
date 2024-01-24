#ifndef DOG_H
#define DOG_H

#include <stdlib.h>

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

/**
 * struct dog - structure that takes in dog information
 *
 * @name: Name of the dog
 * @age: age of the dock
 * @owner: Owner's name
 */

typedef struct dog
{
	char *name;
	float age;
	char *owner;
}dog;

#endif /* DOG_H */
