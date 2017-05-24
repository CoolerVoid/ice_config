#include "ice_config.h"
#include "ice_config_mem.h"
#define MAX_file_len 100000000

char *ice_config_get(char *param_name, char *content)
{

	if (param_name == NULL) 
	{ 
		ICE_CONFIG_DEBUG("PARSER ERROR: Null Pointer\n");
		return NULL;
	}

	if (content == NULL) 
	{ 
		ICE_CONFIG_DEBUG("PARSER ERROR: Null Pointer\n");
		return NULL;
	}

	char *out=ice_config_xmalloc(1);	
	char *tmp=strstr(content,param_name),*p=content;
	int i=0,pos=0,line=0,len_param=strnlen(param_name,64);
	size_t tmplen=2;

	memset(out,0,1);
	
	if (tmp!=NULL)
        	pos =(int) (tmp - content); 

	if(pos==0)
	{
		ICE_CONFIG_XFREE(out);
		return NULL;
	}

	pos+=len_param;
	p+=pos;

	while(line != 1)
	{ 
		if(*p == '\n' || *p == '\0')
			line++;

		out=ice_config_xreallocarray(out,tmplen,sizeof(char));
		out[i]=*p;
		i++;
		p++;
		tmplen+=1;	
		
   	} 

	out[i-1]='\0';	

	return out;
}


char *ice_config_load(char * filename)
{
    FILE *fp = fopen(filename, "r");
    size_t file_size;
    long pos;
    char *file_contents;

    	if (!fp)
        	return NULL;

    	fseek(fp, 0L, SEEK_END);
    	pos = ftell(fp);

    	if (pos < 0) 
	{
        	fclose(fp);
        	return NULL;
    	}

    	file_size = pos;
    	rewind(fp);
    	file_contents = ice_config_xmallocarray((file_size + 1),sizeof(char));

    	if (!file_contents) 
	{
        	fclose(fp);
        	return NULL;
    	}

    	if (fread(file_contents, file_size, 1, fp) < 1) 
	{
        	if (ferror(fp)) 
		{
            		fclose(fp);
            		ICE_CONFIG_XFREE(file_contents);
            		return NULL;
        	}
    	}

   	fclose(fp);
    	file_contents[file_size] = '\0';

    return file_contents;
}
