
//ls.c - This Program displays the names of all files in the current directory

#include <dirent.h>
#include <stdio.h>
#include <string.h>

DIR* directory;
int *optArg(char **opt, char **path);
int *checkOpt(char **opt, char **path);
int showDirectory (DIR *directory);
void showAllIncludeHiddenFiles (DIR *directory);


int main(int argc, char* argv[])
{

     switch (argc) {
	case 1:
	showDirectory(opendir("."));
	break;
	case 2:
        showDirectory(opendir(argv[1]));
	break;
	case 3:
	*checkOpt(&argv[1], &argv[2]);
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
	printf("Could not open current directory\n");
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


int *checkOpt(char** opt, char** path) {
  if ((*opt[0] == '-')&& (strlen(*opt) >= 2))  {
	optArg(opt, path);
  }else {
	printf("Not a valid option.\n");
  }

}

int *optArg(char** opt, char** path)
{
  directory = opendir(*path);

  if (strcmp(*opt,"-a") == 0) {
	showAllIncludeHiddenFiles(directory);
  }else{
	printf("Not a recognized option.\n");
  }

}

void showAllIncludeHiddenFiles(DIR *directory)
{
  struct dirent *entry;

  while ((entry = readdir(directory)))
	printf("%s\n", entry->d_name);
	closedir(directory);

}
