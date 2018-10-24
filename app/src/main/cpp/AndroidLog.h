#ifndef _ANDROID_LOG_
#define _ANDROID_LOG_

#include <jni.h>
#include <android/log.h>

#define  LOG_TAG    "GL2"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#endif //_OBJ_LOAD_H_