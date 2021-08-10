package com.example.newapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.content.DialogInterface;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    private Button button1, button2, button3, button4, button5, button6, button7, button8, button9, button0;
    private Button buttonDivide, buttonMultiply, buttonMinus, buttonPlus;
    private Button buttonClear, buttonEqual, buttonPoint;
    private TextView txt;
    private double m,n;
    private String sr;
    private String sq;
    private Toast toast;
    private String pointNumber;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        txt=(TextView)findViewById(R.id.editText);
        button0=(Button)findViewById(R.id.button0);
        button1=(Button)findViewById(R.id.button1);
        button2=(Button)findViewById(R.id.button2);
        button3=(Button)findViewById(R.id.button3);
        button4=(Button)findViewById(R.id.button4);
        button5=(Button)findViewById(R.id.button5);
        button6=(Button)findViewById(R.id.button6);
        button7=(Button)findViewById(R.id.button7);
        button8=(Button)findViewById(R.id.button8);
        button9=(Button)findViewById(R.id.button9);
        buttonDivide=(Button)findViewById(R.id.buttonDivide);
        buttonMultiply=(Button)findViewById(R.id.buttonMultiply);
        buttonPlus=(Button)findViewById(R.id.buttonPlus);
        buttonMinus=(Button)findViewById(R.id.buttonMinus);
        buttonEqual=(Button)findViewById(R.id.buttonEqual);
        buttonClear=(Button)findViewById(R.id.buttonClear);
        buttonPoint=(Button)findViewById(R.id.buttonPoint);
        button0.setOnClickListener(new numberClick());
        button1.setOnClickListener(new numberClick());
        button2.setOnClickListener(new numberClick());
        button3.setOnClickListener(new numberClick());
        button4.setOnClickListener(new numberClick());
        button5.setOnClickListener(new numberClick());
        button6.setOnClickListener(new numberClick());
        button7.setOnClickListener(new numberClick());
        button8.setOnClickListener(new numberClick());
        button9.setOnClickListener(new numberClick());
        buttonClear.setOnClickListener(new calculateClick());
        buttonPoint.setOnClickListener(new calculateClick());
        buttonPlus.setOnClickListener(new calculateClick());
        buttonMinus.setOnClickListener(new calculateClick());
        buttonMultiply.setOnClickListener(new calculateClick());
        buttonDivide.setOnClickListener(new calculateClick());
        buttonEqual.setOnClickListener(new equalClick());

        sq="!";
        pointNumber="!";
        m=5201314;
        n=5201314;
    }

    class numberClick implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            int flag=11;
            if (v == button0){
                flag=0;
            }

            if (v == button1){
                flag=1;
            }

            if (v == button2){
                flag=2;
            }
            if (v == button3){
                flag=3;
            }

            if (v == button4){
                flag=4;
            }

            if (v == button5){
                flag=5;
            }
            if (v == button6){
                flag=6;
            }

            if (v == button7){
                flag=7;
            }

            if (v == button8){
                flag=8;
            }
            if (v == button9){
                flag=9;
            }

            if (txt.getText().toString().equals("0")){
                txt.setText(Integer.toString(flag));
            }else {
                switch (flag) {
                    case 0:txt.setText(txt.getText().toString()+"0");break;
                    case 1:txt.setText(txt.getText().toString()+"1");break;
                    case 2:txt.setText(txt.getText().toString()+"2");break;
                    case 3:txt.setText(txt.getText().toString()+"3");break;
                    case 4:txt.setText(txt.getText().toString()+"4");break;
                    case 5:txt.setText(txt.getText().toString()+"5");break;
                    case 6:txt.setText(txt.getText().toString()+"6");break;
                    case 7:txt.setText(txt.getText().toString()+"7");break;
                    case 8:txt.setText(txt.getText().toString()+"8");break;
                    case 9:txt.setText(txt.getText().toString()+"9");break;
                    default:break;


                }
            }
        }
    }

    class calculateClick implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            String mm = txt.getText().toString();
            String nn = "";
            int flag1 = 0;
            String mn="";
            int flag2=0;
            char a[] = mm.toCharArray();
            for (int i = 0; i < mm.length(); i++) {
                if (flag1 == 1) {
                    nn = nn + a[i];
                }
                if (a[i] == '+' || (a[i] == '-' && i != 0) || a[i] == '*' || a[i] == '/') {      //设定i!=0主要是为了防止负数使flag1直接变为1
                    flag1 = 1;
                }

            }
            flag1 = 0;
            for (int i = 0; i < mm.length(); i++) {

                if (a[i] == '+' || (a[i] == '-' && i != 0) || a[i] == '*' || a[i] == '/') {      //设定i!=0主要是为了防止负数使flag1直接变为1
                    flag2 = 1;
                }
                if (flag2 == 0) {
                    mn = mn + a[i];
                }

            }
            flag2 = 0;
            if (v == buttonClear) {
                txt.setText("0");
                sq = "!";
                pointNumber = "!";
            }
            if (v == buttonPoint) {
                if (pointNumber.equals("!")) {
                    txt.setText(txt.getText().toString() + ".");
                    pointNumber = "!!";
                }
            }
            if (v == buttonPlus) {
                if (sq.equals("!")) {
                    m = Double.valueOf(txt.getText().toString());
                    sr = "+";
                    txt.setText(txt.getText().toString() + "+");
                    sq = "+";
                    pointNumber = "!";
                } else {
                    if (!(nn.equals("")||nn.equals("."))) {
                        if (sr.equals("+")) {
                            m = Double.valueOf(mn) + Double.valueOf(nn);
                            txt.setText(Double.toString(m) + "+");

                        }
                        if (sr.equals("-")) {
                            m = Double.valueOf(mn) - Double.valueOf(nn);
                            txt.setText(Double.toString(m) + "+");
                        }
                        if (sr.equals("*")) {
                            m = Double.valueOf(mn) * Double.valueOf(nn);
                            txt.setText(Double.toString(m) + "+");
                        }
                        if (sr.equals("/")) {
                            if (Double.valueOf(nn) == 0) {
                                Toast.makeText(getApplicationContext(), "除数为0，请重新输入", Toast.LENGTH_LONG).show();
                            } else {
                                m = Double.valueOf(mn) / Double.valueOf(nn);
                                txt.setText(Double.toString(m) + "+");
                            }
                        }
                        sr="+";
                        pointNumber="!";
                    }
                }
            }
            if (v == buttonMinus) {
                if (sq.equals("!")) {
                    m = Double.valueOf(txt.getText().toString());
                    sr = "-";
                    txt.setText(txt.getText().toString() + "-");
                    sq = "-";
                    pointNumber = "!";
                }
                else {
                    if (!(nn.equals("")||nn.equals("."))) {
                        if (sr.equals("+")) {
                            m = Double.valueOf(mn) + Double.valueOf(nn);
                            txt.setText(Double.toString(m) + "-");

                        }
                        if (sr.equals("-")) {
                            m = Double.valueOf(mn) - Double.valueOf(nn);
                            txt.setText(Double.toString(m) + "-");
                        }
                        if (sr.equals("*")) {
                            m = Double.valueOf(mn) * Double.valueOf(nn);
                            txt.setText(Double.toString(m) + "-");
                        }
                        if (sr.equals("/")) {
                            if (Double.valueOf(nn) == 0) {
                                Toast.makeText(getApplicationContext(), "除数为0，请重新输入", Toast.LENGTH_LONG).show();
                            } else {
                                m = Double.valueOf(mn) / Double.valueOf(nn);
                                txt.setText(Double.toString(m) + "-");
                            }
                        }
                        sr="-";
                        pointNumber="!";
                    }
                }
            }
            if (v == buttonMultiply) {
                if (sq.equals("!")) {
                    m = Double.valueOf(txt.getText().toString());
                    sr = "*";
                    txt.setText(txt.getText().toString() + "*");
                    sq = "*";
                    pointNumber = "!";
                } else {
                    if (!(nn.equals("")||nn.equals("."))) {
                        if (sr.equals("+")) {
                            m = Double.valueOf(mn) + Double.valueOf(nn);
                            txt.setText(Double.toString(m) + "*");

                        }
                        if (sr.equals("-")) {
                            m = Double.valueOf(mn) - Double.valueOf(nn);
                            txt.setText(Double.toString(m) + "*");
                        }
                        if (sr.equals("*")) {
                            m = Double.valueOf(mn) * Double.valueOf(nn);
                            txt.setText(Double.toString(m) + "*");
                        }
                        if (sr.equals("/")) {
                            if (Double.valueOf(nn) == 0) {
                                Toast.makeText(getApplicationContext(), "除数为0，请重新输入", Toast.LENGTH_LONG).show();
                            } else {
                                m = Double.valueOf(mn) / Double.valueOf(nn);
                                txt.setText(Double.toString(m) + "*");
                            }
                        }
                        sr="*";
                        pointNumber="!";
                    }
                }
            }

            if (v == buttonDivide) {
                if (sq.equals("!")) {
                    m = Double.valueOf(txt.getText().toString());
                    sr = "/";
                    txt.setText(txt.getText().toString() + "/");
                    sq = "/";
                    pointNumber = "!";
                }else {
                    if (!(nn.equals("")||nn.equals("."))) {
                        if (sr.equals("+")) {
                            m = Double.valueOf(mn) + Double.valueOf(nn);
                            txt.setText(Double.toString(m) + "/");

                        }
                        if (sr.equals("-")) {
                            m = Double.valueOf(mn) - Double.valueOf(nn);
                            txt.setText(Double.toString(m) + "/");
                        }
                        if (sr.equals("*")) {
                            m = Double.valueOf(mn) * Double.valueOf(nn);
                            txt.setText(Double.toString(m) + "/");
                        }
                        if (sr.equals("/")) {
                            if (Double.valueOf(nn) == 0) {
                                Toast.makeText(getApplicationContext(), "除数为0，请重新输入", Toast.LENGTH_LONG).show();
                            } else {
                                m = Double.valueOf(mn) / Double.valueOf(nn);
                                txt.setText(Double.toString(m) + "/");
                            }
                        }
                        sr="/";
                        pointNumber="!";
                    }
                }
            }

        }
    }

    class equalClick implements View.OnClickListener{
        @Override
        public void onClick(View v) {
            String mm = txt.getText().toString();
            String nn = "";
            int flag1 = 0;
            pointNumber = "!!";
            char a[] = mm.toCharArray();
            for (int i = 0; i < mm.length(); i++) {
                if (flag1 == 1) {
                    nn = nn + a[i];
                }
                if (a[i] == '+' || (a[i] == '-' && i != 0) || a[i] == '*' || a[i] == '/') {      //设定i!=0主要是为了防止负数使flag1直接变为1
                    flag1 = 1;
                }

            }
            if (nn.equals(".")) {
                Toast.makeText(getApplicationContext(), "除数为.，请重新输入", Toast.LENGTH_LONG).show();
            } else {
                if (!nn.equals("")) {
                    n = Double.valueOf(nn);
                    if (sr.equals("+")) {
                        m = m + n;
                        txt.setText(mm+"="+Double.toString(m));
                    }
                    if (sr.equals("-")) {
                        m = m - n;
                        txt.setText(mm+"="+Double.toString(m));
                    }
                    if (sr.equals("*")) {
                        m = m * n;
                        txt.setText(mm+"="+Double.toString(m));
                    }
                    if (sr.equals("/")) {
                        if (n == 0) {
                            Toast.makeText(getApplicationContext(), "除数为0，请重新输入", Toast.LENGTH_LONG).show();
                        } else {
                            m = m / n;
                            txt.setText(mm+"="+Double.toString(m));
                        }
                    }
                }
            }
        }

    }

    class okClick implements DialogInterface.OnClickListener{
        @Override
        public void onClick(DialogInterface dialog, int which) {
            dialog.cancel();
        }
    }



}
