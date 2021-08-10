package com.example.memorythingbook;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.io.FileInputStream;
import java.io.FileOutputStream;

public class MainActivity extends AppCompatActivity {
    private Button exit,inputstream,outputstream;
    private EditText input;
    final String filename="jishi.txt";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        exit=(Button) findViewById(R.id.exit);
        inputstream=(Button) findViewById(R.id.inputstream);
        outputstream=(Button) findViewById(R.id.outputstream);
        input=(EditText) findViewById(R.id.input);
        exit.setOnClickListener(new mclick());
        inputstream.setOnClickListener(new mclick());
        outputstream.setOnClickListener(new mclick());
    }
    class mclick implements View.OnClickListener{
        @Override

        public void onClick(View v) {
            if (v==inputstream){
                FileInputStream fileInputStream;
                String str="";
                byte[] buffer=new byte[1024];
                try {
                    fileInputStream=openFileInput(filename);
                    int bytes=fileInputStream.read(buffer);
                    str=new String(buffer,0,bytes);
                    input.setText(str);
                }
                catch (Exception e){
                    Log.w("errread","文件读取失败");
                }

            }


            if (v==outputstream){
                String str=input.getText().toString();
                FileOutputStream fileOutputStream;
                try{
                    fileOutputStream=openFileOutput(filename, Context.MODE_PRIVATE);
                    fileOutputStream.write(str.getBytes());
                }catch (Exception e){
                    Log.w("errwrite","写入失败");
                }

            }

            if (v==exit){
               outputstream.setClickable(false);
               inputstream.setClickable(false);
                Toast.makeText(getApplicationContext(),"退出成功，读取和保存按钮已经失效",Toast.LENGTH_SHORT).show();
            }


        }

    }


}
