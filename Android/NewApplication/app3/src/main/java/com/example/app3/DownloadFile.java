package com.example.app3;

import android.content.Context;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import org.apache.commons.io.FileUtils;

import java.io.FileOutputStream;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;


public class DownloadFile extends AppCompatActivity {

    EditText et1, et2;
    Button btn1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.download_file);

        et1 = (EditText)findViewById(R.id.editText);
        et2 = (EditText)findViewById(R.id.editText2);
        btn1 = (Button)findViewById(R.id.button);

        et1.setText("https://downloads.apache.org//commons/io/binaries/commons-io-2.8.0-bin.tar.gz");

        btn1.setOnClickListener(new myClick());

    }

    class myClick implements View.OnClickListener {

        @Override
        public void onClick(View v) {
            downLoad(et1.getText().toString(), et2.getText().toString());
        }
    }

    /**
     * 从服务器下载文件
     * @param path 下载文件的地址
     * @param FileName 文件名字
     */
    public void downLoad(final String path, final String FileName) {
        new Thread(new Runnable() {//开启新的线程进行文件下载
            @Override
            public void run() {
                try {
                    URL url = new URL(path);
                    HttpURLConnection con = (HttpURLConnection) url.openConnection();
                    con.setReadTimeout(5000);
                    con.setConnectTimeout(5000);
                    con.setRequestProperty("Charset", "UTF-8");
                    con.setRequestMethod("GET");
                    if (con.getResponseCode() == 200) {
                        InputStream is = con.getInputStream();//获取输入流
                        FileOutputStream fileOutputStream = null;//文件输出流
                        if (is != null) {
                            // FileUtils fileUtils = new FileUtils();
                            // fileOutputStream = new FileOutputStream(fileUtils.getFile(FileName));//指定文件保存路径，
                            fileOutputStream = openFileOutput(FileName, Context.MODE_PRIVATE);
                            byte[] buf = new byte[1024];
                            int ch;
                            while ((ch = is.read(buf)) != -1) {
                                fileOutputStream.write(buf, 0, ch);//将获取到的流写入文件中
                            }
                        }
                        if (fileOutputStream != null) {
                            fileOutputStream.flush();
                            fileOutputStream.close();
                        }
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }).start();//新线程的启动
        Toast toast = Toast.makeText(getApplicationContext(), "下载成功", Toast.LENGTH_LONG);
        toast.setGravity(Gravity.CENTER, 0, 0);
        toast.show();
    }



}
