package com.willkamp.example;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;

import com.willkamp.swig.Example;

public class MainActivity extends AppCompatActivity {

    private final Example _example = new Example();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView versionTv = (TextView) findViewById(R.id.version_tv);
        versionTv.setText(getString(R.string.hello_jni, _example.getVersion()));

    }
}
