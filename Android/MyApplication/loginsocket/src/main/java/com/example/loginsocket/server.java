package com.example.loginsocket;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class server {
    private ServerSocket ss;
    private Socket socket;
    private DataInputStream dis;
    private DataOutputStream dos;
    String user=MainActivity.user;
    String password =MainActivity.password;
    public server(){
        new ServerThread().start();
    }
    class ServerThread extends Thread{
        @Override
        public void run() {
            try {
                ss = new ServerSocket(4001);
                while (true) {
                 socket=ss.accept();
                 dis=new DataInputStream(socket.getInputStream());
                 dos=new DataOutputStream(socket.getOutputStream());
                 String ff=dis.readUTF();
                 String a[]=ff.split("-");

                     if (a[0].equals("xhw") && a[1].equals("2018121015")) {
                         dos.writeUTF("true");
                         dos.flush();
                         MainActivity.user = "";
                         MainActivity.password = "";
                     } else {
                         dos.writeUTF("false");
                         dos.flush();
                     }

                }
            } catch (Exception e) {
                System.out.println(user);
                System.out.println(password);
                System.out.println("读写错误");
            }
                finally{
                    try {
                        dis.close();
                        dos.close();
                    }catch (IOException e){
                        e.printStackTrace();
                    }
                }

            }

        }

    public static void main(String[] args) throws IOException{
        new server();
    }
    }

