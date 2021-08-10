package com.example.loginsocket;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.util.concurrent.FutureTask;

public class MainActivity extends AppCompatActivity {
    Button button;
    String msg="";
    EditText username, inputPassword;
    public static String user;
    public static String password;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        username =(EditText) findViewById(R.id.user);
        inputPassword =(EditText) findViewById(R.id.passworld);
        button=findViewById(R.id.loginlbotton);
        button.setOnClickListener(new myClick());
    }

    class myClick implements View.OnClickListener{
        @Override
        public void onClick(View v) {
             client();
        }
        public void client(){
                 String ff="";
                 user = username.getText().toString();
                 password = inputPassword.getText().toString();
                System.out.println(user);
                 if (user.equals("")|| password.equals("")){
                     Toast.makeText(getApplicationContext(),"请不要输入空的字符",Toast.LENGTH_SHORT).show();
                 }else {
                     connSocket conn = new connSocket();
                     try {
                         FutureTask<String> msg = new FutureTask<String>(conn);
                         new Thread(msg).start();
                         ff = msg.get();
                     } catch (Exception e) {
                         Log.w("err5", "连接错误");
                     }

                     if (ff.equals("true")) {
                         Intent intent = new Intent(MainActivity.this, loginsucess.class);
                         startActivity(intent);
                         Log.w("success", "1");
                     } else {
                         Intent intent = new Intent(MainActivity.this, loginerro.class);
                         startActivity(intent);
                         Log.w("err123", "0");

                     }
                 }
        }

    }

}
