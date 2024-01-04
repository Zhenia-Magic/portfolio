#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
 #define MAX_FILES 1000
#define MAX_NAME_LENGTH 256
 int contains_char(const char *str, char target) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == target) {
            return 1;
        }
    }
    return 0;
}

 size_t my_strlen(const char *s) {
    const char *start = s;
    while (*s)
        s++;
    return s - start;
}

 int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

 char *my_strcpy(char *dest, const char *src) {
    char *save = dest;
    while ((*dest++ = *src++));
    return save;
}

 char *my_strncpy(char *dest, const char *src, size_t n) {
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}

 int is_directory(const char *path) {
    struct stat statbuf;
    stat(path, &statbuf);
    return S_ISDIR(statbuf.st_mode);
}

 int is_regular_file(const char *path) {
    struct stat statbuf;
    stat(path, &statbuf);
    return S_ISREG(statbuf.st_mode);
}

 void read_arguments(char *arguments, int *show_hidden_files, int *sort_by_time) {
    if (contains_char(arguments, 'a')) {
        *show_hidden_files = 1;
    }
    if (contains_char(arguments, 't')) {
        *sort_by_time = 1;
    }
}

 typedef struct {
    time_t sec;
    long nsec;
} TimeStamp;

 TimeStamp last_modification_time(const char *dir, const char *filename) {

     char *path = malloc(MAX_NAME_LENGTH);
    if (path) {
        my_strcpy(path, dir);
        my_strcpy(path + my_strlen(dir), "/");
        my_strcpy(path + my_strlen(dir) + 1, filename);
    }

    struct stat file_stat;
    stat(path, &file_stat);
    free(path);

     TimeStamp ts;
    ts.sec = file_stat.st_mtim.tv_sec;
    ts.nsec = file_stat.st_mtim.tv_nsec;

    return ts;
}

 int compare_files(const char* dir, const char* file1, const char* file2, int sort_by_time) {
    if (sort_by_time) {
        TimeStamp time1 = last_modification_time(dir, file1);
        TimeStamp time2 = last_modification_time(dir, file2);

         // Sort newer files first
        if (time1.sec == time2.sec) {
            return time2.nsec - time1.nsec;
        } else {
            return time2.sec - time1.sec;
        }
    }

     // If times are the same or not sorting by time, sort lexicographically
    return my_strcmp(file1, file2);
}

 void merge(char filenames[MAX_FILES][MAX_NAME_LENGTH], int l, int m, int r, int sort_by_time, const char *dir) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

     char L[n1][MAX_NAME_LENGTH], R[n2][MAX_NAME_LENGTH];

     for (i = 0; i < n1; i++)
        my_strcpy(L[i], filenames[l + i]);
    for (j = 0; j < n2; j++)
        my_strcpy(R[j], filenames[m + 1 + j]);

     i = 0;
    j = 0;
    k = l;

     while (i < n1 && j < n2) {
        if (compare_files(dir, L[i], R[j], sort_by_time) <= 0) {
            my_strcpy(filenames[k], L[i]);
            i++;
        } else {
            my_strcpy(filenames[k], R[j]);
            j++;
        }
        k++;
    }

     while (i < n1) {
        my_strcpy(filenames[k], L[i]);
        i++;
        k++;
    }

     while (j < n2) {
        my_strcpy(filenames[k], R[j]);
        j++;
        k++;
    }
}

 void merge_sort(char filenames[MAX_FILES][MAX_NAME_LENGTH], int l, int r, int sort_by_time, const char *dir) {
    if (l < r) {
        int m = l + (r - l) / 2;

         merge_sort(filenames, l, m, sort_by_time, dir);
        merge_sort(filenames, m + 1, r, sort_by_time, dir);

         merge(filenames, l, m, r, sort_by_time, dir);
    }
}

 void print_directory_contents(char * dir_name, int sort_by_time, int show_hidden_files, int last_dir,
                              int print_dir_name) {
    DIR *d;
    struct dirent *dir;
    d = opendir(dir_name);
    char filenames[MAX_FILES][MAX_NAME_LENGTH];
    int file_count = 0;

     if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_name[0] != '.' || show_hidden_files) {
                my_strncpy(filenames[file_count], dir->d_name, MAX_NAME_LENGTH - 1);
                filenames[file_count][MAX_NAME_LENGTH - 1] = '\0';
                file_count++;
            }
        }
        closedir(d);
    }

     merge_sort(filenames, 0, file_count - 1, sort_by_time, dir_name);

     if (print_dir_name) {
        printf("%s:\n", dir_name);
    }

     for (int i = 0; i < file_count; i++) {
        printf("%s\n", filenames[i]);
    }
    if (!last_dir) {
        printf("\n");
    }
}

 int main(int argc, char **argv) {
    int show_hidden_files = 0, sort_by_time = 0, args_num = 0, last_dir = 0, print_dir_name = 1;
    char filenames[MAX_FILES][MAX_NAME_LENGTH];
    int file_count = 0;
    char dirnames[MAX_FILES][MAX_NAME_LENGTH];
    int dir_count = 0;

     for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            read_arguments(argv[i], &show_hidden_files, &sort_by_time);
            args_num++;
        }
        else {
            if (is_directory(argv[i])) {
                my_strncpy(dirnames[dir_count], argv[i], MAX_NAME_LENGTH - 1);
                dirnames[dir_count][MAX_NAME_LENGTH - 1] = '\0';
                dir_count++;
            }
            else if (is_regular_file(argv[i])) {
                my_strncpy(filenames[file_count], argv[i], MAX_NAME_LENGTH - 1);
                filenames[file_count][MAX_NAME_LENGTH - 1] = '\0';
                file_count++;
            }
        }
    }

     merge_sort(filenames, 0, file_count - 1, sort_by_time, ".");
    merge_sort(dirnames, 0, dir_count - 1, sort_by_time, ".");

     for (int i = 0; i < file_count; i++) {
        printf("%s\n", filenames[i]);
    }
    if (dir_count > 0 && file_count > 0) {
        printf("\n");
    }
    else if (dir_count == 1 && file_count == 0) {
        print_dir_name = 0;
    }

     for (int i = 0; i < dir_count; i++) {
        if (i == dir_count - 1) {
            last_dir = 1;
        }
        print_directory_contents(dirnames[i], sort_by_time, show_hidden_files, last_dir, print_dir_name);
    }


     if (argc == args_num + 1) {
        print_directory_contents(".", sort_by_time, show_hidden_files, 1, 0);
    }

     return 0;
}
