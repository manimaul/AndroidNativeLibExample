package com.willkamp.example;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;

import com.willkamp.swig.Example;
import com.willkamp.swig.NetCxx;

public class MainActivity extends AppCompatActivity {

    private final Example _example = new Example();
    private final NetCxx _netCxx = new NetCxx();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView versionTv = (TextView) findViewById(R.id.version_tv);
        versionTv.setText(getString(R.string.hello_jni, _example.getVersion()));
        NetCxx.Response response = _netCxx.post("http://example.com", "{\"user_name\":\"user\",\"password\":\"user\"}");
        Log.d("RESPONSE body", response.getBody());
        Log.d("RESPONSE error", response.getError());
        Log.d("RESPONSE code", String.valueOf(response.getResponse_code()));
    }
}
