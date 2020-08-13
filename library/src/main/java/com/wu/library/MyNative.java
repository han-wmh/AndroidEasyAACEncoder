package com.wu.library;

/**
 * 项目名称:    AndroidEasyAACEncoder
 * 类描述:
 * 作者:        wmh
 * 创建时间:     2020/7/17 9:33
 * 更新时间:     2020/7/17 9:33
 * 更新备注:
 * 版本号:       1.0
 */
public class MyNative {
    public static native void init(String path);
    public static native void close();
}
