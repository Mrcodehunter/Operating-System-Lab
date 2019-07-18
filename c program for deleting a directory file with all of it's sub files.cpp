#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
 
int deletedirectory(const char *dirname)
{
    DIR *dir;
    struct dirent *entry;
    char path[PATH_MAX];
 
  
    dir = opendir(dirname);
    if (dir == NULL) {
        perror("Error opendir()");
        return 0;
    }
 
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {
            snprintf(path, (size_t) PATH_MAX, "%s/%s", dirname, entry->d_name);
            if (entry->d_type == DT_DIR) {
                deletedirectory(path);
            }
           
        }
 
    }
    closedir(dir);
    //Actually not deleting just printing
    // Deletion statement will place here
    
    printf(" Deleted: %s\n", dirname);
 
    return 1;
}
 
 
int main()
{
    char answer[10],in[100];
    int yes, no;
    
    printf("Enter directory name : ");
    scanf("%s",in);
 
        printf("\nAre you sure you want to delete the entire directory %s?\n",
               in);
        scanf("%s",answer);
        yes = !strcmp(answer, "yes");
        no = !strcmp(answer, "no");
        if (no) {
            printf("\nexit...\n");
            return 0;
        } else if (yes) {
           
            return !deletedirectory(in);
        } else {
            printf("\nPlease answer exactly yes or no.\n");
        }
   
    return 0;
}
 
