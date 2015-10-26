package com.willkamp.example;

import android.app.Application;

public class ExampleApp extends Application {
    static {
        System.loadLibrary("AndroidNativeLibExample");
    }
}
