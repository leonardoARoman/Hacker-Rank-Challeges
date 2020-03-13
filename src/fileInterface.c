#include "fileInterface.h"

///////////////////////////////////////////////////////////////////////////////////
// @param fileName 	-csv file name
///////////////////////////////////////////////////////////////////////////////////
bool isFile(char *fileName)
{
  FILE *stream;
  if ((stream = fopen(fileName,"r"))!=NULL)
  {
    fclose((FILE*)stream);
    return true;
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////////
// @param fileName 	-csv file name
// @param edge 	-csv file name
///////////////////////////////////////////////////////////////////////////////////
int fileSize(char *fileName, Edge_t edge)
{
  const int SIZE = 1024;
  int i = 0;
  // TODO opening files may be expensive, may need to pass a FILE as argument
  FILE *stream = fopen(fileName,"r");
  char buff[SIZE];
  if(edge == row)
  {
    while (fgets(buff,SIZE,(FILE*)stream)) 	/* stream line by line from file to buffer 	*/
      i++;									/* number of rows counted 					*/

    fclose((FILE*)stream);
    return i;
  }
  if (edge == column)
  {
    fgets(buff,SIZE,(FILE*)stream); /* stream the first line in file to buffer  */
    char *str = strdup(buff);		/* point to a copy of buff 					*/
    char *token = strtok(str,",");	/* point to the first string before a comma */
    while (token!=NULL)				/* traverse all commas 						*/
    {
      i++;							/* number of columns counted 				*/
      token = strtok(NULL,",");		/* point to next string before a comma 		*/
    }
    fclose((FILE*)stream);
    free(str);
    return i;
  }
  fclose((FILE*)stream);
  return i;
}

void built_file()
{

}
