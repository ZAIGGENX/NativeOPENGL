#ifndef _OBJ_LOAD_H_
#define _OBJ_LOAD_H_

#include <jni.h>

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "AndroidLog.h"

using namespace std;
//typedef unsigned int INTEGER;
typedef int INTEGER;

class objFile{

private:
    static const int MAX_FILES = 300;

    int m_fileName;
    char* files[MAX_FILES];

public:
    char* nameMod;

    objFile();
    ~objFile();

    void Init();
    void Cleanup();

    INTEGER writeFile(char *obj_file, char *text);
    INTEGER loadFile(char *obj_file);

};

#endif //_OBJ_LOAD_H_