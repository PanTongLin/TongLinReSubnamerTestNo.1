#include<stdio.h> 
#include<string.h>
#include<conio.h>

int main(int argc,char* argv[])
{
	for(int i=0; i<argc; i++)
	{
		char origin[20];
		strcpy(origin, strrchr(argv[i+1], '\\') + 1);
		char then[20];
		strcpy(then, origin);
		strcpy(then, strcat(strtok(then,"."), ".png"));
		
		printf("%s %s\n",origin,then);
		
		int result = rename(origin, then);
		
		if(result != 0)
		{
			perror("error");
			break;
		}
	}
	
	getch();
	
	return 0;
}

