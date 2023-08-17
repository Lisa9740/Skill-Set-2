//ls.c - This Program displays the names of all files in the current directory

#include <dirent.h>
#include <stdio.h>

int main(void)
{
    struct dirent *dir;

    DIR *d;
    d = opendir(".");

    if (d == NULL)
    {
	printf("Could not open current directory");
	return 0;
    }

     while ((dir = readdir(d)) != NULL)
    	printf("%s\n", dir->d_name);
     	closedir(d);

     return 0;

}
