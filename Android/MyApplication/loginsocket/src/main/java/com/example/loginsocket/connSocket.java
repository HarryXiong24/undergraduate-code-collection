package com.example.loginsocket;

import android.util.Log;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.SocketAddress;
import java.util.concurrent.Callable;

public class connSocket implements Callable<String> {

    private Socket socket=null;
    private DataOutputStream dos=null;
    private DataInputStream dis=null;
    String IP="192.168.24.1";
    private String temp;
    @Override
    public String call() throws Exception {
        try {
            socket=new Socket();
            SocketAddress socketAddress=new InetSocketAddress(IP,4001);
            socket.connect(socketAddress,5000);
            dos=new DataOutputStream(socket.getOutputStream());
            dis=new DataInputStream(socket.getInputStream());
            String ff= MainActivity.user +"-"+MainActivity.password;
            Log.w("fffff",ff);
            dos.writeUTF(ff);
            dos.flush();
            this.temp =dis.readUTF();
        }catch (Exception e){
            this.temp ="socket错误";
        }
        return temp;
    }

}
