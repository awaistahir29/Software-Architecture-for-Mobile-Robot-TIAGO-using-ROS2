
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>
  
int main() 
{ 
    int fd1;
    int fd2; 
  
    char * fifoz = "/tmp/fifoz"; 
    mkfifo(fifoz, 0666); 

    char * fifocy = "/tmp/fifocy"; 
    mkfifo(fifocy, 0666); 
    
  
  char input_string[80], send_string[80]; 
    char str1[80], str2[80]; 
    char format_string[80]="%d,%d";
    char format_string2[80]="%d,%d";
    int n1, n2;
    double mean;

    while (1) 
    { 
    
        fd1 = open(fifoz,O_RDONLY); 
        fd2 = open(fifocy,O_WRONLY); 
        read(fd1, str1, 80); 
 
        
        
            /* read numbers from input line */
            sscanf(str1, format_string, &n1);
            printf("The Command is to :\n"); 
           if (n1==1)
           	printf("Increased in x-axis\n");
           else if (n1==2)
            	printf("Decrease in x-axis\n");
           else if (n1==3)
            	printf("Stop in x-axis\n");
           else if (n1==4)
           	printf("Increased in z-axis\n");
           else if (n1==5)
           	printf("Decrease in z-axis\n");
           else if (n1==6)
           	printf("Stop in z-axis\n");
            
            sprintf(str2, format_string2, n1, n2);
            write(fd2,str2, strlen(str2)+1);
            close(fd1); 
            close(fd2);
        
    } 
    
    return 0; 
} 
