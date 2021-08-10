package com.example.player;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {
    private Button stopPlay;
    public static Button startPlay;
    Intent intent;
    String state;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        startPlay=(Button)findViewById(R.id.startpaly);
        stopPlay=(Button)findViewById(R.id.stopplay);
        startPlay.setOnClickListener(new mclick());
        stopPlay.setOnClickListener(new mclick());
        IntentFilter intentFilter=new IntentFilter("abcd");
        registerReceiver(new Receiver(), intentFilter);
        intent=new Intent(MainActivity.this, Server.class);

    }
    class mclick implements View.OnClickListener{
        @Override
        public void onClick(View v) {
            if (v==startPlay) {
                if (v.getId()==R.id.startpaly){
                    state="start";
                }
                Bundle bundle=new Bundle();
                bundle.putString("state",state);
                intent.putExtras(bundle);
                MainActivity.this.startService(intent);
            }
            if (v==stopPlay){
                stopService(intent);
            }
        }
    }
}
