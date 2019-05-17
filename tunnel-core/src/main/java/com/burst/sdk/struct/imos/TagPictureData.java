package com.burst.sdk.struct.imos;

import com.sun.jna.Pointer;
import com.sun.jna.Structure;

import java.util.Arrays;
import java.util.List;

/**
 * @描述: 存放解码后图像数据的指针和长度等信息的结构体定义
 * @作者: 任琳珺
 * @时间: 2019/3/13 17:24
 */
public class TagPictureData extends Structure {
    byte[] date = new byte[4];                  /**< pucData[0]:Y 平面指针,pucData[1]:U 平面指针,pucData[2]:V 平面指针 */
    int ulLineSize[] = new int[4];              /**< ulLineSize[0]:Y平面每行跨距, ulLineSize[1]:U平面每行跨距, ulLineSize[2]:V平面每行跨距 */
    int ulPicHeight;                          /**< 图片高度 */
    int ulPicWidth;                           /**< 图片宽度 */
    int ulRenderTimeType;                     /**< 用于渲染的时间数据类型，对应tagRenderTimeType枚举中的值 */
    long dlRenderTime;                         /**用于渲染的时间数据**/

    public TagPictureData(){
        super();
    }
    public TagPictureData(Pointer pointer) {
        super(pointer);
    }

    public List<String> getFieldOrder() {
        return Arrays.asList("date","ulLineSize","ulPicHeight","ulPicWidth",
                                "ulRenderTimeType","dlRenderTime");
    }

    public static  interface ByReference extends Structure.ByReference {};

    public static  interface ByValue extends Structure.ByValue {};


}
