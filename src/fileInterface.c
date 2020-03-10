#include "fileInterface.h"

///////////////////////////////////////////////////////////////////////////////////
// @param fileName 	-csv file name
///////////////////////////////////////////////////////////////////////////////////
bool isFile(char *fileName){
  FILE *stream;
  if ((stream = fopen(fileName,"r"))!=NULL) {
    fclose((FILE*)stream);
    return true;
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////////
// @param fileName 	-csv file name
// @param edge 	-csv file name
///////////////////////////////////////////////////////////////////////////////////
int fileSize(char *fileName, Edge_t edge){
  const int SIZE = 1024;
  int i = 0;
  FILE *stream = fopen(fileName,"r");
  char buff[SIZE];
  if(edge == row){
    while (fgets(buff,SIZE,(FILE*)stream)) {
      i++;
    }
    fclose((FILE*)stream);
    return i;
  }if (edge == column) {
    fgets(buff,SIZE,(FILE*)stream);
    char *next_line = strdup(buff);
    char *token = strtok(next_line,",");
    while (token!=NULL) {
      i++;
      token = strtok(NULL,",");
    }
    fclose((FILE*)stream);
    return i;
  }
  fclose((FILE*)stream);
  return i;
}

void built_file(){

}
