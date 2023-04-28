#include <stdio.h>

/**
 * myBeginnerFun - Put the constructor attribute to myBeginnerFun() so that it
 *   is executed before main()
 */
void myBeginnerFun(void) __attribute__ ((constructor));

/**
 * myBeginnerFun - starting of myBeginnerFun
 */
void myBeginnerFun(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
