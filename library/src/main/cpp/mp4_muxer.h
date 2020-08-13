//
// Created by zhd0821 on 2020/7/16.
//

#ifndef HYWMAINPRJ_MP4_MUXER_H
#define HYWMAINPRJ_MP4_MUXER_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "include/mp4v2/general.h"
#include "include/EasyAACEncoderAPI.h"
#include "log.h"

class Mp4Muxer {

public:
    InitParam initParam;
    Easy_Handle handle;
    unsigned int bAACBufferSize;
    unsigned char *pbAACBuffer;
    unsigned int aac_len;
    MP4FileHandle mp4;
    MP4TrackId video;
    MP4TrackId audio;
    int fps;
};


#endif //HYWMAINPRJ_MP4_MUXER_H
