package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    private EditText edit1;
    private EditText edit2;
    private EditText edit3;
    private Button button;

    @Override    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        edit1 = (EditText)findViewById(R.id.editView1);
        edit2 = (EditText)findViewById(R.id.editView2);
        edit3 = (EditText)findViewById(R.id.editView3);
        button = (Button)findViewById(R.id.button);
        button.setOnClickListener(new myClick());
    }

    class myClick implements View.OnClickListener {

        @Override
        public void onClick(View v) {
            String res;
            double num1 = Double.parseDouble(edit1.getText().toString());
            double num2 = Double.parseDouble(edit2.getText().toString());

            res = String.valueOf(num1 + num2);

            edit3.setText(res);
        }
    }
}