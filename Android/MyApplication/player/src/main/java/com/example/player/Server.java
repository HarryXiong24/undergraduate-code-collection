package com.example.player;

import android.app.Service;
import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.os.IBinder;
import android.widget.Toast;

import androidx.annotation.Nullable;

public class Server extends Service {
    MediaPlayer play;
    int flag=0,flag1=0;
    private Intent intent;
    private Bundle bundle;


    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override
    public void onCreate() {
        super.onCreate();
        play=MediaPlayer.create(this, R.raw.music);
        Toast.makeText(this,"播放器资源启动中.......",Toast.LENGTH_SHORT).show();
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        super.onStartCommand(intent, flags, startId);
        play.setVolume(1f,1f);
        if (flag==0&&flag1==0){
            play.start();
            Toast.makeText(this,"音乐播放中",Toast.LENGTH_SHORT).show();
            flag=1;
            flag1=1;
        }
        if (flag==1&&flag1==0){
            play.pause();
            Toast.makeText(this,"音乐暂停中",Toast.LENGTH_SHORT).show();
            flag=0;
            flag1=1;
        }
        flag1=0;
        sendbrodcastbyflag(flag);
        return START_STICKY;
    }

    @Override
    public void onDestroy() {
        play.release();
        super.onDestroy();
        Toast.makeText(this,"音乐播放器已关闭",Toast.LENGTH_SHORT).show();
    }

    private void sendbrodcastbyflag(int flag){
        intent=new Intent();
        intent.setAction("abcd");
        bundle=new Bundle();
        bundle.putInt("flag",flag);
        intent.putExtras(bundle);
        sendBroadcast(intent);
    }
}
