#include "ObjLoad.h"

objFile::objFile()
{
    LOGE(" INITIALIZE ");
}

objFile::~objFile()
{
    LOGE(" Destruct objFile ");
    //Cleanup();
}

INTEGER objFile::writeFile(char *obj_file, char *text) {

    LOGE(" writeFile %s", text);

    FILE* file = fopen(obj_file,"w+");

    LOGE(" writeFile 001");

    if (file != NULL)
    {
        LOGE(" writeFile 002");
        fputs(text, file);
        LOGE(" writeFile 003");
        fflush(file);
        fclose(file);
    }

    return 0;
}

INTEGER objFile::loadFile(char *obj_file){

    FILE * pFile;
    long lSize;
    char * buffer;
    size_t result;

    pFile = fopen ( obj_file , "rb" );
    if (pFile == NULL) {
        fputs ("File error",stderr);
        return 1;
        //exit (1);
    }

    // obtain file size:
    fseek (pFile , 0 , SEEK_END);
    lSize = ftell (pFile);
    rewind (pFile);

    // allocate memory to contain the whole file:
    buffer = (char*) malloc (sizeof(char)*lSize);
    if (buffer == NULL) {
        fputs ("Memory error",stderr);
        return 2;
    }

    // copy the file into the buffer:
    result = fread (buffer,1,lSize,pFile);
    if (result != lSize) {
        fputs ("Reading error",stderr);
        return (3);
    }

    /* the whole file is now loaded in the memory buffer. */

    // terminate
    fclose (pFile);
    LOGE(" file %s content: %s", obj_file, buffer );

    free (buffer);
    return 0;
}
