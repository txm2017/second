/*#include<stdio.h>
 
main()
{
    FILE *fp;
    char buffer[2560];
    fp = popen("cat /root/t.conf", "r");
    if (buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0'; //去除换行符
        }
    fgets(buffer, sizeof(buffer), fp);
    printf("%s", buffer);
    pclose(fp);
}

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
        FILE* fp = NULL;
        char cmd[5120];
        sprintf(cmd, "cat /root/t.conf");
        if ((fp = popen(cmd, "r")) != NULL)
        {
                fgets(cmd, sizeof(cmd), fp);
                                pclose(fp);
        }

                  
        printf("cmd is %s\n", cmd);

        return 0;
}

#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>

int main( void ) 
{ 
   FILE   *stream; 
   FILE   *wstream;
   char   buf[1024]; 
     
    memset( buf, '\0', sizeof(buf) );//初始化buf,以免后面写如乱码到文件中
    stream = popen( "ls /root/cert", "r" ); //将“ls －l”命令的输出 通过管道读取（“r”参数）到FILE* stream
    wstream = fopen( "test.txt", "w+"); //新建一个可写的文件

    fread( buf, sizeof(char), sizeof(buf), stream); //将刚刚FILE* stream的数据流读取到buf中
    fwrite( buf, 1, sizeof(buf), wstream );//将buf中的数据写到FILE    *wstream对应的流中，也是写到文件中
    
    pclose( stream );  
    fclose( wstream );
    
    return 0;
}   


#include <stdio.h>
#include <string.h>
 
void executeCMD(const char *cmd, char *result)
{
    char buf_ps[1024];
    char ps[1024]={0};
    FILE *ptr;
    strcpy(ps, cmd);
    if((ptr=popen(ps, "r"))!=NULL)
    {
        while(fgets(buf_ps, 1024, ptr)!=NULL)
        {
//	       可以通过这行来获取shell命令行中的每一行的输出
//	   	   printf("%s", buf_ps);
           strcat(result, buf_ps);
           if(strlen(result)>1024)
               break;
        }
        pclose(ptr);
        ptr = NULL;
    }
    else
    {
        printf("popen %s error\n", ps);
    }
}
 
int main()
{
        char result[1024]={0};
        executeCMD("ls /root/cert", result);
//      这行是将每一行的输出拼接之后获取到了result字符串中了
        printf("%s", result);
        return 0;
}*/

////

#include <stdio.h>
#include <string.h>
 
void main()
{
    char buf_ps[1024] = {0};
    //char result[1024];
    char *ps = "ls /root/cert";
    FILE *ptr;
    FILE *f;
    f=fopen("test.txt", "w+"); 
    if((ptr=popen(ps, "r"))!=NULL)
    {
        while(fgets(buf_ps, 1024, ptr)!=NULL)
        {
	   printf("%s", buf_ps);
	   fputs(buf_ps,f);
	   //strcat(result, buf_ps);
           if(strlen(buf_ps)>1024)
               break;
        }
        pclose(ptr);
        ptr = NULL;
    }
    else
    {
        printf("popen %s error\n", ps);
    }
    //fputs(result,f);
    fclose(f);

    
    
}
 

