#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef enum Edge {row,column} Edge_t;

bool isFile(char*);
int fileSize(char*, Edge_t);
int getFileSize(FILE*, Edge_t);
void built_file();
