package com.wu.androideasyaacencoder;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

import com.wu.library.MyNative;

/**
 * easyAACEncoder和MP4V2库
 */
public class MainActivity extends AppCompatActivity {
    static {
        System.loadLibrary("easyaacencoder");
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        MyNative.init("aaa");
        MyNative.close();
    }
}
