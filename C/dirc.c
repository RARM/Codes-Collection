// dirc.c -- Example of how to open and read folder in c. From C for Dummies.
// This program is a simple example of how to read directories in C. It prints
// all the files and directories inside the folder where it is called.

#include <stdio.h>
#include <dirent.h>

int main(void) {
	DIR *folder;
	struct dirent *entry;
	int files = 0;

	folder = opendir(".");
	if (folder == NULL) {
		perror("Unable to read directory.\n");
		return 1;
	}

	while ( (entry = readdir(folder)) ) {
		files++;
		printf("File %3d: %s\n", files, entry->d_name);
	}

	closedir(folder);

	return 0;
}
