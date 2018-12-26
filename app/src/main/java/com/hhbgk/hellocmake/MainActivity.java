package com.hhbgk.hellocmake;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.hhbgk.hellocmake.impl.Player;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'hello_cmake' library on application startup.
    static {
        System.loadLibrary("hello_cmake");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());

        Player player = new Player();
        player.create(3, "hello");

        Player player2 = new Player();
        player2.create(1, "hello2");
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
