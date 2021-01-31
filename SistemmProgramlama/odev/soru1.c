/*
*B181210378
*Sevim Suna Kalayci
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

typedef unsigned long int UI;

extern edata;
extern end;

int A = 4;
int X;
int B = 6;
int Y;

char *deneme;

void proc_a()
{

}

int main(int argc, char **argv)
{
	int i;
	char *buf;
	
	buf = (char *) malloc(200);
	
	printf("Page size: %d\n", getpagesize());
	printf("\n");
	
	printf("Data bölümü: başlangıç = 0x%lx,		boyut = 20480 byte\n", (UI) &edata);
	printf("&end: 0x%lx\n", (UI) &end);
	printf("\n");
	
	printf("Yığıt bölümü: başlangıç = 0x%lx,		boyut = 135168 byte\n", (UI) buf);
	printf("\n");

	printf("Yığın bölümü: başlangıç = 0x%lx,		boyut = 135168 byte\n", (UI) &i);
	printf("\n");
	
	/*sprintf(buf, "cat /proc/%d/maps", getpid());
	printf(buf);
	deneme = system(buf);
	printf("%s",deneme);
	sprintf(buf, "pmap -x %d", getpid());*/
	
	//system(buf);
	return 0;
}


