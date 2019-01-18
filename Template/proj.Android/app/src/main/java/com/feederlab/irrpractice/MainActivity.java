package com.feederlab.irrpractice;

import android.app.Activity;
import android.app.NativeActivity;
import android.os.Bundle;

public class MainActivity extends NativeActivity {

    // Used to load the 'native-lib' library on application startup.
    //static {
    //    System.loadLibrary("native-lib");
    //}

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        // Example of a call to a native method
        //android.util.Log.d("MainActivity", stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    //public native String stringFromJNI();
}
