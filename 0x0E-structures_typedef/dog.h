#ifndef DOG_H
#define DOG_H

#include <stdlib.h>

/**
 * struct dog - structure that takes in dog information
 *
 * @name: Name of the dog
 * @age: age of the dock
 * @owner: Owner's name
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif /* DOG_H */
