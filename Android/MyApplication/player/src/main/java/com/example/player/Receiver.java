package com.example.player;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;

public class Receiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        int flag = intent.getExtras().getInt("flag");
        if (flag==1){
            MainActivity.startPlay.setText("暂停");
        }
        if (flag==0){
            MainActivity.startPlay.setText("播放");
        }
    }
}
