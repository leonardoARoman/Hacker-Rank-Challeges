#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef enum Edge {row,column} Edge_t;

bool isFile(char*);
bool split(char**, char*);
int fileSize(char*, Edge_t);
int getFileSize(FILE*, Edge_t);
void built_file();
