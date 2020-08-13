
#include <jni.h>
#include "log.h"
#include "include/EasyAACEncoderAPI.h"
#include "include/mp4v2/file_prop.h"
#include "include/mp4v2/file.h"
#include "include/mp4v2/sample.h"
#include "include/mp4v2/track.h"
#include "mp4_muxer.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void

JNICALL
Java_com_wu_library_MyNative_init(JNIEnv *env, jclass type, jstring fileName_) {
    LOGD("test_mp4-->mp4MuxerInit -->start");
    const char *fileName = env->GetStringUTFChars(fileName_, nullptr);
    int ret = 0;
//    int ret = mp4_muxer_init(fileName);

    LOGD("test_mp4-->mp4MuxerInit -->ret: %d", ret);
    env->ReleaseStringUTFChars(fileName_, fileName);
}

JNIEXPORT void

JNICALL
Java_com_wu_library_MyNative_close(JNIEnv *env, jclass type) {
//    Mp4Muxer *mp4Muxer = new Mp4Muxer;
//    Easy_AACEncoder_Release(mp4Muxer->handle);
//    free(mp4Muxer->pbAACBuffer);
//    MP4Close(mp4Muxer->mp4);
//    delete mp4Muxer;
    LOGD("test_mp4-->closeMp4 -->close");
}

#ifdef __cplusplus
}
#endif
