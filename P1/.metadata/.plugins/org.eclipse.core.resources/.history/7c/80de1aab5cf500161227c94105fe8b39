#include "threads.h"
#include <stdio.h>

void one();
void two();

char *text = "LIFE";
char *text1 = "DEATH";

int main()
{
	RunQ = NewItem();
	InitQueue(&RunQ);
	start_thread(one);
	start_thread(two);
	run();
	return 0;
}

void one()
{
	int i = 0;
	while(i == 0)
	{
		printf("%s\n", text);
		yield();
	}
}

void two()
{
	int i = 0;
	while(i == 0)
	{
		printf("%s\n", text1);
		yield();
	}
}
