#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <libgen.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
	char directory_path[PATH_MAX];
	FILE *fp;
	openlog("linux-assignment2", LOG_PID, LOG_USER);
	if(argc < 3) {
		syslog(LOG_ERR, "Expected at least 2 arguments");
		return 1;
	}
	syslog(LOG_INFO,"Directory = %s, String = %s\n", argv[1], argv[2]);
	strcpy(directory_path, argv[1]);
	char *directory = dirname(directory_path);
	DIR *dir = opendir(directory);
    	if(dir == NULL) {
        	if(errno == ENOENT) {
            		// Directory does not exist, try to create it
            		int result = mkdir(directory, 0777);
            		if(result != 0) {
                		syslog(LOG_ERR, "Failed to mkdir %s", directory);
                		return 1;
            		}
       		} else {
            		syslog(LOG_ERR, "Error opening directory: %s", directory);
            		return 1;
        	}
    	} else {
        	closedir(dir);  // Close the directory if it was successfully opened
    	}

	fp = fopen(argv[1], "w");
	if(fp == NULL) {
		syslog(LOG_ERR, "Error opening file");
		return 1;
	}
	fprintf(fp, "%s", argv[2]);
	return 0;
}
