//
// Created by autulin on 2018/9/11.
//

#ifndef GB28181TEST_LOG_H
#define GB28181TEST_LOG_H

#include <android/log.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
};
#endif

#define LOG_TAG "GB28181" // 这个是自定义的LOG的标识
#define DEBUG true
#define LOG(level, TAG, ...) if(DEBUG){__android_log_print(level, TAG, __VA_ARGS__);}
#define LOGD(...) if(DEBUG){__android_log_print(ANDROID_LOG_DEBUG,LOG_TAG ,__VA_ARGS__);} // 定义LOGD类型
#define LOGI(...) if(DEBUG){__android_log_print(ANDROID_LOG_INFO,LOG_TAG ,__VA_ARGS__);} // 定义LOGI类型
#define LOGW(...) if(DEBUG){__android_log_print(ANDROID_LOG_WARN,LOG_TAG ,__VA_ARGS__);} // 定义LOGW类型
#define LOGE(...) if(DEBUG){__android_log_print(ANDROID_LOG_ERROR,LOG_TAG ,__VA_ARGS__);} // 定义LOGE类型

#endif //GB28181TEST_LOG_H

