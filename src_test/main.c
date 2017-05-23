#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/ice_config.h"

int main() 
{
	char *content_test=ice_config_load("config_map.cfg");
 	puts(content_test);

 	char *var1_test=ice_config_get("MONITOR=",content_test);
 	printf("Example get MONITOR \n Result:%s \n",var1_test);

	free(var1_test);
	var1_test=NULL;

	return 0;
}
