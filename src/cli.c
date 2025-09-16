#include "cli.h"
#include "core.h"
#include "list.h"
#include <stdio.h>
#include <dirent.h>

int cli_run(int argc, char *argv[]) {
    Node* extensions = NULL;

    for(int index = 1; index < argc; index ++) {
        insertAtBeginning(&extensions, argv[index]);
    }

    core_function(extensions);
    return 0;
}

