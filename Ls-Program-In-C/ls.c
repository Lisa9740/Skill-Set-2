//ls.c - This Program displays the names of all files in the current directory

#include <dirent.h>
#include <stdio.h>
#include <string.h>


int *optArg(char **opt, char **path);
int showDirectory (DIR *directory);
void showAllWithHiddenFiles (DIR *directory);

int main(int argc, char* argv[])
{
    DIR *directory;

     switch (argc) {
	case 1:
	showDirectory(opendir("."));
	break;
	case 2:
        showDirectory(opendir(argv[1]));
	break;
	case 3:
	*optArg(&argv[1], &argv[2]);
	break;
	default:
	printf("Too much argument used. ls [option] [path]");
	break;
    }

     return 0;

}


int showDirectory(DIR* directory){
   struct dirent *entry;

   if (directory == NULL) {
	printf("Could not open current directory");
   }

   while ((entry = readdir(directory)) != NULL)
       if (entry->d_name[0] != '.'
	&& strcmp(entry->d_name, ".") != 0
	  && strcmp(entry->d_name, "..") != 0)
	{
		printf("%s\n", entry->d_name);
	}
	closedir(directory);

}

int *optArg(char** opt, char** path)
{

  DIR *directory = opendir(*path);
  struct dirent *entry;

  if (strcmp(*opt,"-a") == 0) {
	showAllWithHiddenFiles(directory);
  }

}

void showAllWithHiddenFiles(DIR *directory)
{
  struct dirent *entry;

  while ((entry = readdir(directory)))
	printf("%s\n", entry->d_name);
	closedir(directory);

}
