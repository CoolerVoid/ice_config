#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
//#include "ice_config_mem.h"

char *ice_config_load(char * NameFile);
char *ice_config_get(char *param_name, char *content);
