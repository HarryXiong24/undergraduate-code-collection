package com.example.app4;

import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;
public class DBHelper extends SQLiteOpenHelper {

    static final String Database_name = "PhoneBook.db";
    static final int Database_Version = 1;
    SQLiteDatabase db;
    public int id_this;
    Cursor cursor;

    // Users（_id（不是id）,username, usertel, useraddress, useremail）
    String TABLE_NAME = "Users";
    String ID = "_id";
    String username = "username";
    String usertel = "usertel";
    String useraddress = "useraddress";
    String useremail = "useremail";

    public DBHelper(Context context) {
        super(context, Database_name, null, Database_Version);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        String sql = "CREATE TABLE " + this.TABLE_NAME + " ("
                + this.ID + " INTEGER PRIMARY KEY autoincrement, "
                + this.username + " text not null, "
                + this.usertel + " text not null, "
                + this.useraddress + " text not null, "
                + this.useremail + " text not null " + ");" ;
        db.execSQL(sql);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

    }
}
