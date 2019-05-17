package com.burst.video;

import org.apache.tomcat.util.buf.ByteBufferUtils;
import org.jcodec.codecs.h264.H264Decoder;

import java.nio.ByteBuffer;

/**
 * @描述:
 * @作者: REN
 * @时间: 2019/5/15 17:35
 */
public class DecoderVideo {

    public static void decoder() {
        H264Decoder decoder = new H264Decoder();
    }


}
