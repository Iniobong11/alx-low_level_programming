#include "dog.h"

/**
 * init_dog - initializing the structures of a dog type
 * @d: structure pointer
 * @name: dog name pointer
 * @age: dog name
 * @owner: dog owner pointer
 *
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
