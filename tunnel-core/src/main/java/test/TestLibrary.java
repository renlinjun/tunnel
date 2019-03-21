package test;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.ptr.IntByReference;

/**
 * @描述:
 * @作者: REN
 * @时间: 2018/12/25 17:32
 */
public interface TestLibrary extends Library {
    //TestLibrary INSTANCE = null;
    String arch = System.getProperty("os.arch");
    String os= System.getProperty("os.name");

    TestLibrary INSTANCE = Native.load("test/test_64",TestLibrary.class);

    int add(int a, int b);

    void addArray(IntByReference a, IntByReference b, IntByReference c, int len);

    String stringFun(String a, String b);
}
