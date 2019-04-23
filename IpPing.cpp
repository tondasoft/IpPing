
#include "stdafx.h"
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
 
int ping(char * ip) 
{ 
    int ok = 1; 
	FILE * f = 0; 
    char cmd[80]=""; 
	sprintf(cmd, "ping %s > ping.txt", ip); 
    system(cmd); 
    f = fopen("ping.txt", "r"); 
    if(!f) 
		return 0; 
    while(!feof(f)) 
	{ 
       fgets(cmd, 80, f); 
       if(strstr(cmd, "timed out")) 
	   {
		   ok = 0;
		   break;
	   }		    
    }
	fclose(f);
    system("del ping.txt"); 
    return ok; 
}  
 
int main(int argc, char* argv[])
{ 
    int ok = ping("192.168.1.1"); 
    if(ok) 
		printf("目标连通！"); 
	else 
		printf("网络不通！"); 
    return 0; 
} 
