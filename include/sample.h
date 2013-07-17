#ifndef _SAMPLE_H_
#define _SAMPLE_H_

#include <libavcodec/avcodec.h>
#include "context.h"

i2DASHError i2dash_sample_add_frame(i2DASHContext *context, AVFrame *frame);
i2DASHError i2dash_sample_add(i2DASHContext *context, uint8_t * buf,
                              int buf_len, int dts, int key_frame);

#endif
