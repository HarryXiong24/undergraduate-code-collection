package com.example.app3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    SharedPreferences settings;
    TextView textView, textView2;
    EditText name, password;
    CheckBox checkBox;
    Button button;
    Intent intent;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textView = (TextView)findViewById(R.id.textView);
        textView2 = (TextView)findViewById(R.id.textView2);
        name = (EditText)findViewById(R.id.editTextTextPersonName);
        password = (EditText)findViewById(R.id.editTextTextPassword);
        checkBox = (CheckBox)findViewById(R.id.checkBox);
        button = (Button)findViewById(R.id.button);
        settings = getSharedPreferences("login", Context.MODE_PRIVATE);
        intent = new Intent(MainActivity.this, DownloadFile.class);

        String f1 = settings.getString("name","");
        String f2 = settings.getString("password","");
        name.setText(f1);
        password.setText(f2);

        button.setOnClickListener(new myClick());

    }

    class myClick implements View.OnClickListener {

        @Override
        public void onClick(View v) {

            if (!checkBox.isChecked()) {
                SharedPreferences.Editor editor = settings.edit();
                editor.putString("name", "");
                editor.putString("password", "");
                editor.commit();
            }

            if (checkBox.isChecked() && name.getText().toString().contentEquals("xhw") &&
                    password.getText().toString().contentEquals("123456")) {

                SharedPreferences.Editor editor = settings.edit();
                editor.putString("name", name.getText().toString());
                editor.putString("password", password.getText().toString());
                editor.commit();
                startActivity(intent);
            }

            if (name.getText().toString().contentEquals("xhw") && password.getText().toString().contentEquals("123456") == true) {
                startActivity(intent);
            }

            if ( (name.getText().toString().contentEquals("xhw") && password.getText().toString().contentEquals("123456")) == false ) {
                System.out.println(name.getText().toString());
                System.out.println(password.getText().toString());
                Toast.makeText(getApplicationContext(),"你输入的账号或者密码错误", Toast.LENGTH_SHORT).show();
            }
        }
    }
}