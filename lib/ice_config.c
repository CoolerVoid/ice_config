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


char *ice_config_load(char * NameFile)
{
	FILE * fh;
	static char buffer[MAX_file_len];

	memset(buffer,0,MAX_file_len);

	fh = fopen(NameFile, "rb");

	if( fh == NULL )
	{

		ICE_CONFIG_DEBUG("error in to open() file");
		perror("Error ");
		exit(-1); 	 
		
	}

	if(fseek(fh, 0L, SEEK_END)==0)
	{
    		long s = ftell(fh);
    		rewind(fh);

    		if ( buffer != NULL && s < MAX_file_len )
    		{
      			if(!fread(buffer, s, 1, fh))
				ICE_CONFIG_DEBUG("error \n");
    		}
	}

 
	if( fclose(fh) == EOF )
	{
		ICE_CONFIG_DEBUG("Error in close() file %s",NameFile);
		exit(1);
	}

	fh=NULL;

	char *tmp=buffer;
	
	return tmp;
}
