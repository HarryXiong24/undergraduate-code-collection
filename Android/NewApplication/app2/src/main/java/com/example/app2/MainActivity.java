package com.example.app2;

import androidx.appcompat.app.AppCompatActivity;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.SimpleAdapter;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MainActivity extends AppCompatActivity {

    private String[] data = {
        "Apple",
        "Banana",
        "Orange",
        "Watermelon",
        "Pear"
    };

    ListView listView; // 数据

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        listView = (ListView)findViewById(R.id.ListView1);

        ArrayAdapter<String> adapter = new ArrayAdapter<String>(
                MainActivity.this,            // Context上下文
                android.R.layout.simple_list_item_1,  // 子项布局id
                this.data);

        listView.setAdapter(adapter);


        int[] headerID = {R.drawable.logo,R.drawable.logo2,
                R.drawable.logo,R.drawable.logo2,R.drawable.logo};

        List<Map<String, Object>> listTest = new ArrayList<Map<String, Object>>();

        for(int i = 0; i < data.length; i++){
            Map<String, Object> listItem = new HashMap<String, Object>();
            listItem.put("header", headerID[i]);
            listItem.put("name", data[i]);
            listTest.add(listItem);
        }

        SimpleAdapter simpleAdapter = new SimpleAdapter(
            this,                 //上下文
            listTest,                     //数据源，包含map的List
            R.layout.list_array,          //自定义的列表项的布局文件
            new String[] {"header", "name"},
            new int[] {R.id.header, R.id.name});

        listView.setAdapter(simpleAdapter);

        listView.setOnItemClickListener(new mItemClick());
    }

    class mItemClick implements AdapterView.OnItemClickListener {

        AlertDialog.Builder dialog = new AlertDialog.Builder(MainActivity.this);

        @Override
        public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
            dialog.setTitle("您选择的水果");
            dialog.setMessage(data[position]);
            dialog.setPositiveButton("确定", new okClick());
            dialog.create();
            dialog.show();
        }
    }

    class okClick implements DialogInterface.OnClickListener {

        @Override
        public void onClick(DialogInterface dialog, int which) {
            dialog.cancel();
        }
    }
}