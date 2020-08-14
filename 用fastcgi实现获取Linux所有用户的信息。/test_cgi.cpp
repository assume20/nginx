#include <iostream>
#include <fcgi_stdio.h>
#include <unistd.h>  
#include <stdio.h>  
#include <dirent.h>  
#include <sys/stat.h>  
#include <stdlib.h>  
#include <string>

using namespace std;

int main()
{
	while (FCGI_Accept() >= 0)
	{
		printf("Content-type: text/html\r\n");
		printf("\r\n");
		printf("<title>fast CGI Hello! </title>");
        
        DIR *dir;
        struct dirent *ptr;
        
        dir = opendir("/home");
        
        std::string userName;
        
        printf("<h1>当前系统含有用户为</h1>\n");
        while((ptr = readdir(dir)) != NULL)
        {
            if (std::string(ptr->d_name) != "."
                    && std::string(ptr->d_name) != "..")
            {    
                userName = userName + ptr->d_name + " ";
            }
        }
        
        printf("<h2>%s</h2>", userName.c_str());
        
        std::cout << "doudou" << std::endl;

        closedir(dir);
	}

	return 0;
}
