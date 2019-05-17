package com.burst.sdk.struct.imos;

import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

/**
 * @描述: 存放拼帧后视频数据的指针和长度等信息的结构体定义
 * @作者: 任琳珺
 * @时间: 2019/4/12 16:45
 */
public class TagParseVideoData extends Structure {

    public byte[] pucData;             /**< 视频数据指针 */
    public int ulDataLen;            /**< 视频数据长度 */
    public int ulVideoFrameType;     /**< 视频帧类型，从#XP_VIDEO_FRAME_TYPE_E中取值 */
    public int ulVideoCodeFormat;    /**< 视频编码格式，从#XP_VIDEO_ENCODE_TYPE_E中取值 */
    public int ulHeight;             /**< 视频图像高度 */
    public int ulWidth;              /**< 视频图像宽度 */
    public long dlTimeStamp;          /**< 时间戳（毫秒）*/
    public int ulReserved1;          /**< 保留参数 */
    public int ulReserved2;          /**< 保留参数 */

    public TagParseVideoData() {
        super();
    }

    public TagParseVideoData(Pointer pointer) {
        super(pointer);
    }

    protected List<String> getFieldOrder() {
        return Arrays.asList("pucData","ulDataLen",
                "ulVideoFrameType","ulVideoCodeFormat","ulHeight",
                "ulWidth","dlTimeStamp","ulReserved1","ulReserved2"
        );
    }

    public static class ByReference extends TagParseVideoData implements Structure.ByReference {
    };
    public static class ByValue extends TagParseVideoData implements Structure.ByValue {

    };
}
