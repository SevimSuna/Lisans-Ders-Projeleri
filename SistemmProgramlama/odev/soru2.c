/*
*B181210378
*Sevim Suna Kalayci
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include "fields.h"

int main(int argc, char **argv2)
{
  IS is;
  int i;
  int fd;
  off_t size;
  char *kelime[1000];
	char *strcpy = "strcpy(";
	char *strcat = "strcat(";
	char *sprintf= "sprintf(";
	char *gets   = "gets(";
	char *getpw  = "getpw(";
	char *secici1 = "-r";
	char *secici2 = "-s";
  int a = 0;
	int karsilastir[5];
	int karsilastir2[2];

  if (argc < 2) { fprintf(stderr, "usage: printwords filename\n"); exit(1); }
 	/* Open the file as an inputstruct.  Error check. */

  is = new_inputstruct(argv2[2]);
  if (is == NULL) {
    perror(argv2[2]);
    exit(1);
  }
	karsilastir2[0] = memcmp(argv2[1], secici1, 2);
	if (karsilastir2[0] == 0) 
	{
		while(get_line(is) >= 0) 
		{	    
		  for (i = 0; i < is->NF; i++) {
				kelime[a] = is->fields[i];
				a++;
				karsilastir[0] = memcmp(strcpy, is->fields[i],7);
				if(karsilastir[0] == 0)
				{
					printf("Satır %d: strcpy() kullanılmış, yerine strncpy() kullanmalısınız.\n", is->line);
				}
				karsilastir[1] = memcmp(strcat, is->fields[i],7);
				if(karsilastir[1] == 0)
				{
					printf("Satır %d: strcat() kullanılmış, yerine strncat() kullanmalısınız.\n", is->line);
				}
				karsilastir[2] = memcmp(sprintf, is->fields[i],7);
				if(karsilastir[2] == 0)
				{
					printf("Satır %d: sprintf() kullanılmış, yerine snprintf() kullanmalısınız.\n", is->line);
				}
				karsilastir[3] = memcmp(gets, is->fields[i],7);
				if(karsilastir[3] == 0)
				{
					printf("Satır %d: gets() kullanılmış, yerine fgets() kullanmalısınız.\n", is->line);
				}
				karsilastir[4] = memcmp(getpw, is->fields[i],7);
				if(karsilastir[4] == 0)
				{
					printf("Satır %d: getpw() kullanılmış, yerine getpwuid() kullanmalısınız.\n", is->line);
				}
		  }
		}	
	}
  karsilastir2[1] = memcmp(argv2[1], secici2, 2);
	if (karsilastir2[1] == 0)
	{
		while(get_line(is) >= 0) 
		{	    
		  for (i = 0; i < is->NF; i++) {
				kelime[a] = is->fields[i];
				a++;
				karsilastir[0] = memcmp(strcpy, is->fields[i],7);
				if(karsilastir[0] == 0)
				{
					printf("Satır %d: strcpy() kullanılmış.\n", is->line);
				}
				karsilastir[1] = memcmp(strcat, is->fields[i],7);
				if(karsilastir[1] == 0)
				{
					printf("Satır %d: strcat() kullanılmış.\n", is->line);
				}
				karsilastir[2] = memcmp(sprintf, is->fields[i],7);
				if(karsilastir[2] == 0)
				{
					printf("Satır %d: sprintf() kullanılmış.\n", is->line);
				}
				karsilastir[3] = memcmp(gets, is->fields[i],7);
				if(karsilastir[3] == 0)
				{
					printf("Satır %d: gets() kullanılmış.\n", is->line);
				}
				karsilastir[4] = memcmp(getpw, is->fields[i],7);
				if(karsilastir[4] == 0)
				{
					printf("Satır %d: getpw() kullanılmış.\n", is->line);
				}
		  }
		}
	}
	

  

  jettison_inputstruct(is);
  exit(0);
}
