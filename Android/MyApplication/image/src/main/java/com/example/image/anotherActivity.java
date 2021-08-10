package com.example.image;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class anotherActivity extends AppCompatActivity {
    private Button button;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.another);
        button=(Button)findViewById(R.id.button2);
        button.setOnClickListener(new myClick());
    }
    class myClick implements View.OnClickListener{
        @Override
        public void onClick(View v) {
          Intent intent =new Intent(anotherActivity.this,MainActivity.class);
          startActivity(intent);
        }
    }
}
