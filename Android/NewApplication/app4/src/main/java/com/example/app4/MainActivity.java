package com.example.app4;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.content.ContentValues;
import android.content.Context;
import android.content.DialogInterface;
import android.database.ContentObservable;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.os.Bundle;
import android.view.ContextThemeWrapper;
import android.view.View;
import android.view.inputmethod.EditorInfo;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    static EditText editText1, editText2, editText3, editText4;
    Button prev, next, open, close, add, review, delete;
    Cursor cursor;
    // SQLiteDatabase db;
    DBHelper helper;
    public int id_this;
    Bundle savedInstanceState;

    // Users（_id（不是id）,username, usertel, useraddress, useremail）
    static String TABLE_NAME = "Users";
    static String ID = "_id";
    static String username = "username";
    static String usertel = "usertel";
    static String useraddress = "useraddress";
    static String useremail = "useremail";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        editText1 = (EditText)findViewById(R.id.editText1);
        editText2 = (EditText)findViewById(R.id.editText2);
        editText3 = (EditText)findViewById(R.id.editText3);
        editText4 = (EditText)findViewById(R.id.editText4);

        open = (Button)findViewById(R.id.open);
        open.setOnClickListener(new myClick());

        close = (Button)findViewById(R.id.close);
        close.setOnClickListener(new myClick());

        prev = (Button)findViewById(R.id.prev);
        prev.setOnClickListener(new myClick());

        next = (Button)findViewById(R.id.next);
        next.setOnClickListener(new myClick());

        add = (Button)findViewById(R.id.add);
        add.setOnClickListener(new myClick());

        review = (Button)findViewById(R.id.review);
        review.setOnClickListener(new myClick());

        delete = (Button)findViewById(R.id.delete);
        delete.setOnClickListener(new myClick());
    }

    class myClick implements View.OnClickListener {

        @Override
        public void onClick(View v) {
            switch (v.getId()) {
                case R.id.open:
                    // 建立数据库
                    helper = new DBHelper(MainActivity.this);
                    SQLiteDatabase db = helper.getWritableDatabase();
                    // 打开数据库
                    db = openOrCreateDatabase("PhoneBook.db", Context.MODE_PRIVATE, null);
                    cursor = db.query("Users", null, null, null, null, null, null);
                    cursor.moveToNext();
                    prev.setClickable(true);
                    next.setClickable(true);
                    review.setClickable(true);
                    delete.setClickable(true);
                    break;
                case R.id.close:
                    cursor.close();
                    editText1.setText("数据库已关闭");
                    editText2.setText("数据库已关闭");
                    editText3.setText("数据库已关闭");
                    editText4.setText("数据库已关闭");
                    prev.setClickable(false);
                    next.setClickable(false);
                    review.setClickable(false);
                    delete.setClickable(false);
                    break;
                case R.id.prev:
                    if(!cursor.isFirst()) {
                        cursor.moveToPrevious();
                    }
                    dataShow();
                    break;
                case R.id.next:
                    if(!cursor.isLast()) {
                        cursor.moveToNext();
                    }
                    dataShow();
                    break;
                case R.id.add:
                    add();
                    // onCreate(savedInstanceState);
                    break;
                case R.id.review:
                    review();
                    // onCreate(savedInstanceState);
                    break;
                case R.id.delete:
                    delete();
                    // onCreate(savedInstanceState);
                    break;
            }

        }

        void dataShow() {
            id_this = Integer.parseInt(cursor.getString(0));
            String user_name_this = cursor.getString(1);
            String telephone_this = cursor.getString(2);
            String address_this = cursor.getString(3);
            String mail_this = cursor.getString(4);
            editText1.setText(user_name_this);
            editText2.setText(telephone_this);
            editText3.setText(address_this);
            editText4.setText(mail_this);
        }

        void add() {
            ContentValues values = new ContentValues();
            values.put(username, MainActivity.editText1.getText().toString());
            values.put(usertel, MainActivity.editText2.getText().toString());
            values.put(useraddress, MainActivity.editText3.getText().toString());
            values.put(useremail, MainActivity.editText4.getText().toString());

            String where1 = ID + " = " + id_this;
            SQLiteDatabase db = helper.getWritableDatabase();
            db.insert(TABLE_NAME, null, values);
            db.close();
        }

        void review() {
            ContentValues values = new ContentValues();
            values.put(username, MainActivity.editText1.getText().toString());
            values.put(usertel, MainActivity.editText2.getText().toString());
            values.put(useraddress, MainActivity.editText3.getText().toString());
            values.put(useremail, MainActivity.editText4.getText().toString());

            String where1 = ID + " = " + id_this;
            SQLiteDatabase db = helper.getWritableDatabase();
            db.update(TABLE_NAME, values, where1, null);
            db.close();
        }

        void delete() {
            String where = ID + " = " + id_this;
            SQLiteDatabase db = helper.getWritableDatabase();
            db.delete(TABLE_NAME, where, null);
            db.close();
        }

    }
}