#ifndef DOG_H
#define DOG_H

/*Define a new type struct dog with the following elements:*/
/**
 * struct dog - Our old data-type
 * dog_t - Our typedef data-type
 *
 * @name: first member or instance variable
 * @age: second member or second variable
 * @owner: third member or third variable
 *
 * Description: first description
 */
typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
#endif
