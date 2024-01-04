#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

 int READLINE_READ_SIZE;
char *READLINE_STORAGE;

 void init_my_readline() {
    READLINE_READ_SIZE = 1024;
    if (READLINE_STORAGE != NULL) {
        free(READLINE_STORAGE);
    }
    READLINE_STORAGE = malloc(READLINE_READ_SIZE);
    if (READLINE_STORAGE != NULL) {
        READLINE_STORAGE[0] = '\0';
    }
}

 int find_index_newline(char *str) {
    int ind = 0;
    while (*str) {
        if (*str == '\n') { return ind; }
        str++;
        ind++;
    }
    return -1;
}

 int my_strlen(char *string) {
    int i;
    for (i = 0; string[i] != '\0'; i++);
    return i;
}

 char *my_strcat(char *string1, char *string2) {
    int len1 = my_strlen(string1);
    int len2 = my_strlen(string2);
    char *new_string = malloc(len1 + len2 + 1);
    if (!new_string) {
        return NULL;
    }
    int i;
    for (i = 0; i < len1; i++) {
        new_string[i] = string1[i];
    }
    for (i = 0; i < len2; i++) {
        new_string[i + len1] = string2[i];
    }
    new_string[i + len1] = '\0';
    return new_string;
}

 char *rewrite_buffer_from_ind(char *buffer, int ind) {
    int buffer_len = my_strlen(buffer);
    char *new_buffer = malloc(buffer_len - ind + 1);
    if (!new_buffer) {
        return NULL;
    }
    int i = 0;
    int j = ind;
    while (buffer[j] != '\0') {
        new_buffer[i++] = buffer[j++];
    }
    new_buffer[i] = '\0';
    return new_buffer;
}

 char * check_exiting_storage() {
    if (my_strlen(READLINE_STORAGE) > 0) {
        int newline_ind = find_index_newline(READLINE_STORAGE);
        if (newline_ind >= 0) {
            char *result = rewrite_buffer_from_ind(READLINE_STORAGE, 0);
            result[newline_ind] = '\0';
            char *temp_storage = rewrite_buffer_from_ind(READLINE_STORAGE, newline_ind + 1);
            free(READLINE_STORAGE);
            READLINE_STORAGE = temp_storage;
            return result;
        }
    }
    return NULL;
}

 char *my_readline(int fd) {
    char *temp_buffer = malloc(READLINE_READ_SIZE + 1);

     if (!temp_buffer) {
        return NULL;
    }

     ssize_t bytesRead;
    char *line;

     if ((line = check_exiting_storage()) != NULL) {
        free(temp_buffer);
        return line;
    }

     while ((bytesRead = read(fd, temp_buffer, READLINE_READ_SIZE)) > 0) {
        temp_buffer[bytesRead] = '\0';
        char *concatenated = my_strcat(READLINE_STORAGE, temp_buffer);
        free(READLINE_STORAGE);
        READLINE_STORAGE = concatenated;

         int newline_ind = find_index_newline(READLINE_STORAGE);
        if (newline_ind >= 0) {
            char *result = rewrite_buffer_from_ind(READLINE_STORAGE, 0);
            result[newline_ind] = '\0';
            char *temp_storage = rewrite_buffer_from_ind(READLINE_STORAGE, newline_ind + 1);
            free(READLINE_STORAGE);
            READLINE_STORAGE = temp_storage;
            free(temp_buffer);
            return result;
        }
    }



     free(temp_buffer);
    if (my_strlen(READLINE_STORAGE) > 0) {
        char *final_str = rewrite_buffer_from_ind(READLINE_STORAGE, 0);
        READLINE_STORAGE[0] = '\0';
        return final_str;
    }

     return NULL;
}
