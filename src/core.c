#include "core.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <list.h>

const char *get_extension(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if (!dot || dot == filename) {
        return ""; // No extension or filename starts with a dot
    }
    return dot + 1;
}

void list_directories(const char *path, Node **head) {
    struct dirent *entry;
    DIR *dp = opendir(path);
    if (dp == NULL) {
        perror("opendir");
    }
    
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_DIR) {
            if (strncmp(entry->d_name, ".", 1) != 0) {
                char new_path[1024];
                snprintf(new_path, sizeof(new_path), "%s/%s", path, entry->d_name);
                insertAtBeginning(head, strdup(new_path));
                list_directories(new_path, head);
            }
        }
    }
    closedir(dp);
}

int is_directory_contains_extension(const char *path, const char *extension) {
    struct dirent *entry;
    DIR *dp = opendir(path);
    if (dp == NULL) {
        perror("opendir");
        return 1;
    }
    
    while ((entry = readdir(dp))) {
        if (entry->d_type != DT_DIR) {
            const char *currentFileExt = get_extension(entry->d_name);
            if (strcmp(currentFileExt, extension) == 0) {
                return 1;
            }
        }
    }
    closedir(dp);
    return 0;
}

void printVimPath(Node* head) {
    Node* current = head;
    while (current != NULL) {
        char *coma = ",";
        if(current->next == NULL) {
            coma = "";
        }
        printf("%s,", current->data + 2, coma);
        current = current->next;
    }
}

int core_function(Node* extensions) {
    Node* directories = NULL;
    Node* directories_with_extensions = NULL;


    const char *path = ".";
    list_directories(path, &directories);


    Node* d = directories;
    Node* e = extensions;

    while(directories != NULL) {
        extensions = e;
        while(extensions != NULL) {
            char *ext = extensions->data;
            extensions = extensions->next;
            if(is_directory_contains_extension(directories->data, ext) == 1){
                insertAtBeginning(&directories_with_extensions,
                                  strdup(directories->data));
                extensions = NULL;
            }
        }
        directories = directories->next;
    }

    printVimPath(directories_with_extensions);

    directories = d;
    extensions = e;
    freeList(&directories);
    freeList(&directories_with_extensions);
    freeList(&extensions);

    return 0;
}
