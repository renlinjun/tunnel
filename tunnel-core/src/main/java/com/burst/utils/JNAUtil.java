package com.burst.utils;

import com.sun.jna.Native;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;

/**
 * @描述: JNA工具类
 * @作者: 任琳珺
 * @时间: 2019/3/22 12:27
 */
public class JNAUtil {

    /**
     *
     * 功能描述: 释放指针内存
     *
     * @auther: 任琳珺
     * @date:  2019-03-22
     * @param:
     * @return:
     */
    public static void freeMemory(Pointer p) {
        long peer = Pointer.nativeValue(p);
        Native.free(peer);//手动释放内存
        Pointer.nativeValue(p, 0);
    }

    /*public static Structure[] fromArrayPointer(Pointer pointer, int numberResults,int size) {
        int offset = 0;
        for (int i = 0; i < numberResults; i++) {
            arr[i] = fromPointer(pointer, offset);
            offset += size;
        }
        return arr;
    }*/

    public  static <T extends Structure> T  fromPointer(Pointer pointer, int offset) {
       /* T inst = T.newInstance(T.);
        inst.count = pointer.getShort(offset);
        offset += 2;
        inst.description = pointer.getString(offset);
        pointer.getS
        offset += 40;
        inst.average = pointer.getShort(offset);
        return inst;*/
       return null;
    }
}
