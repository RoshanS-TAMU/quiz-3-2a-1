#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <pwd.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[])
{

/////////////////////////////////////
    DIR *dp;
    struct dirent *dirp;
    if (argc != 2)
        printf("error: please specify a valid file");
    if ((dp = opendir(argv[1])) == NULL)
        printf("error: please specify a valid file");

    chdir(argv[1]);
    while ((dirp = readdir(dp)) != NULL){
        
        struct stat stats;

        if (stat(dirp->d_name,&stats) == 0){
            printf("File name: %s\n", dirp->d_name);
            printf("inode number: %ld \n", stats.st_ino);
            printf("number of links: %ld \n", stats.st_nlink);
            printf("User ID of owner: %d \n", stats.st_uid);
            printf("Group ID of owner: %d \n", stats.st_gid);
            printf("Size in bytes: %ld \n", stats.st_size);

            time_t time = stats.st_atim.tv_sec;
            printf("Last access: %s", ctime(&time));
            time = stats.st_mtim.tv_sec;
            printf("Last modification: %s", ctime(&time));
            time = stats.st_ctim.tv_sec;
            printf("Last status change: %s", ctime(&time));

            printf("Number of disk blocks allocated: %ld \n", stats.st_blocks);
            printf("Access mode in octal: %o \n", stats.st_mode);

            printf("Access mode flags: ");
            (S_IRUSR & stats.st_mode) ? printf("r") : printf("-");
            (S_IWUSR & stats.st_mode) ? printf("w") : printf("-");
            (S_IXUSR & stats.st_mode) ? printf("x") : printf("-");
            (S_IRGRP & stats.st_mode) ? printf("r") : printf("-");
            (S_IWGRP & stats.st_mode) ? printf("w") : printf("-");
            (S_IXGRP & stats.st_mode) ? printf("x") : printf("-");
            (S_IROTH & stats.st_mode) ? printf("r") : printf("-");
            (S_IWOTH & stats.st_mode) ? printf("w") : printf("-");
            (S_IXOTH & stats.st_mode) ? printf("x") : printf("-");
            
        } else {
            printf("ERROR\n");
            printf("\n");
        }
        printf("\n");
        printf("\n");

    }



    closedir(dp);

    exit(0);


/////////////////////////////////////////



}
