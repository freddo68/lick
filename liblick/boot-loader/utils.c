#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include "utils.h"
#include "../utils.h"

/**
 * @brief an opaque structure to hold the attributes of a file
 */
struct attrib_s {
#ifdef _WIN32
    DWORD attrib;
#endif
    char NOT_EMPTY;
};

char *advance_to_newline(char *s) {
    if(s == NULL)
        return NULL;
    while(s[0] != '\0' && s[0] != '\n')
        s++;
    return s;
}

char *file_to_str(FILE *f) {
    int len = 0;
    rewind(f);
    while(getc(f) != EOF)
        len++;
    rewind(f);

    char *buf = malloc(len + 1);
    if(fread(buf, 1, len, f) < len) {
        free(buf);
        return NULL;
    }
    buf[len] = '\0';

    return buf;
}

#ifdef _WIN32
attrib_t *attrib_get(const char *file) {
    attrib_t *attrib = malloc(sizeof(attrib_t));
    attrib->attrib = GetFileAttributes(file);
    return attrib;
}

attrib_t *attrib_open(const char *file) {
    attrib_t *attrib = attrib_get(file);
    SetFileAttributes(file, FILE_ATTRIBUTE_NORMAL);
    return attrib;
}
void attrib_save(const char *file, attrib_t *attrib) {
    SetFileAttributes(file, attrib->attrib);
    free(attrib);
}
#else
attrib_t *attrib_get(const char *file) {
    return NULL;
}
attrib_t *attrib_open(const char *file) {
    return NULL;
}
void attrib_save(const char *file, attrib_t *attrib) {
    return;
}
#endif

int backup_file(const char *f) {
    int len = strlen(f) + strlen(".bak") + 1;
    char buf[len];
    strcat(strcpy(buf, f), ".bak");
    if(!copy_file(buf, f)) {
        return 0;
    }

    attrib_save(buf, attrib_get(f));
}
