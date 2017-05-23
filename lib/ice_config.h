#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>
//#include "ice_config_mem.h"

char *ice_config_load(char * NameFile);
char *ice_config_get(char *param_name, char *content);
