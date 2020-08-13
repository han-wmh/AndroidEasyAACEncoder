#ifndef MP4V2_STREAMING_H
#define MP4V2_STREAMING_H

#include "general.h"

/**************************************************************************//**
 *
 *  @defgroup mp4_hint MP4v2 Streaming
 *  @{
 *
 *****************************************************************************/

MP4V2_EXPORT
bool MP4GetHintTrackRtpPayload(
    MP4FileHandle hFile,
    MP4TrackId    hintTrackId,
    char**        ppPayloadName = nullptr,
    uint8_t*      pPayloadNumber = nullptr,
    uint16_t*     pMaxPayloadSize = nullptr,
    char**        ppEncodingParams = nullptr);

#define MP4_SET_DYNAMIC_PAYLOAD 0xff

MP4V2_EXPORT
bool MP4SetHintTrackRtpPayload(
    MP4FileHandle hFile,
    MP4TrackId    hintTrackId,
    const char*   pPayloadName,
    uint8_t*      pPayloadNumber,
    uint16_t      maxPayloadSize = 0,
    const char *  encode_params = nullptr,
    bool          include_rtp_map = true,
    bool          include_mpeg4_esid = true);

MP4V2_EXPORT
const char* MP4GetSessionSdp(
    MP4FileHandle hFile );

MP4V2_EXPORT
bool MP4SetSessionSdp(
    MP4FileHandle hFile,
    const char*   sdpString );

MP4V2_EXPORT
bool MP4AppendSessionSdp(
    MP4FileHandle hFile,
    const char*   sdpString );

MP4V2_EXPORT
const char* MP4GetHintTrackSdp(
    MP4FileHandle hFile,
    MP4TrackId    hintTrackId );

MP4V2_EXPORT
bool MP4SetHintTrackSdp(
    MP4FileHandle hFile,
    MP4TrackId    hintTrackId,
    const char*   sdpString );

MP4V2_EXPORT
bool MP4AppendHintTrackSdp(
    MP4FileHandle hFile,
    MP4TrackId    hintTrackId,
    const char*   sdpString );

MP4V2_EXPORT
MP4TrackId MP4GetHintTrackReferenceTrackId(
    MP4FileHandle hFile,
    MP4TrackId    hintTrackId );

MP4V2_EXPORT
bool MP4ReadRtpHint(
    MP4FileHandle hFile,
    MP4TrackId    hintTrackId,
    MP4SampleId   hintSampleId,
    uint16_t*     pNumPackets = nullptr);

MP4V2_EXPORT
uint16_t MP4GetRtpHintNumberOfPackets(
    MP4FileHandle hFile,
    MP4TrackId    hintTrackId );

MP4V2_EXPORT
int8_t MP4GetRtpPacketBFrame(
    MP4FileHandle hFile,
    MP4TrackId    hintTrackId,
    uint16_t      packetIndex );

MP4V2_EXPORT
int32_t MP4GetRtpPacketTransmitOffset(
    MP4FileHandle hFile,
    MP4TrackId    hintTrackId,
    uint16_t      packetIndex );

MP4V2_EXPORT
bool MP4ReadRtpPacket(
    MP4FileHandle hFile,
    MP4TrackId    hintTrackId,
    uint16_t      packetIndex,
    uint8_t**     ppBytes,
    uint32_t*     pNumBytes,
    uint32_t      ssrc = 0,
    bool          includeHeader = true,
    bool          includePayload = true);

MP4V2_EXPORT
MP4Timestamp MP4GetRtpTimestampStart(
    MP4FileHandle hFile,
    MP4TrackId    hintTrackId );

MP4V2_EXPORT
bool MP4SetRtpTimestampStart(
    MP4FileHandle hFile,
    MP4TrackId    hintTrackId,
    MP4Timestamp  rtpStart );

MP4V2_EXPORT
bool MP4AddRtpHint(
    MP4FileHandle hFile,
    MP4TrackId    hintTrackId );

MP4V2_EXPORT
bool MP4AddRtpVideoHint(
    MP4FileHandle hFile,
    MP4TrackId    hintTrackId,
    bool          isBframe = false,
    uint32_t      timestampOffset = 0);

MP4V2_EXPORT
bool MP4AddRtpPacket(
    MP4FileHandle hFile,
    MP4TrackId    hintTrackId,
    bool          setMbit = false,
    int32_t       transmitOffset = 0);

MP4V2_EXPORT
bool MP4AddRtpImmediateData(
    MP4FileHandle  hFile,
    MP4TrackId     hintTrackId,
    const uint8_t* pBytes,
    uint32_t       numBytes );

MP4V2_EXPORT
bool MP4AddRtpSampleData(
    MP4FileHandle hFile,
    MP4TrackId    hintTrackId,
    MP4SampleId   sampleId,
    uint32_t      dataOffset,
    uint32_t      dataLength );

MP4V2_EXPORT
bool MP4AddRtpESConfigurationPacket(
    MP4FileHandle hFile,
    MP4TrackId    hintTrackId );

MP4V2_EXPORT
bool MP4WriteRtpHint(
    MP4FileHandle hFile,
    MP4TrackId    hintTrackId,
    MP4Duration   duration,
    bool          isSyncSample = true);

/** @} ***********************************************************************/

#endif /* MP4V2_STREAMING_H */
