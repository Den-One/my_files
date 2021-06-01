package com.denone.logandmess;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import static android.content.ContentValues.TAG;

public class MainActivity extends AppCompatActivity {

    TextView tvOut;
    Button btnOk;
    Button btnCancel;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // find view-elements
        Log.d(TAG, "найдём View-элементы");
        tvOut = (TextView) findViewById(R.id.tvOut);
        btnOk = (Button) findViewById(R.id.btnOk);
        btnCancel = (Button) findViewById(R.id.btnCancel);

        // assigns a handler to buttons
        Log.d(TAG, "присваиваем обработчик кнопкам");
        btnOk.setOnClickListener((View.OnClickListener) this);
        btnCancel.setOnClickListener((View.OnClickListener) this);

        View.OnClickListener oclBtn = new View.OnClickListener() {
            @SuppressLint("SetTextI18n")
            @Override
            public void onClick(View v) {
                switch (v.getId()) {
                    case R.id.btnYes:
                        tvOut.setText("Нажата кнопка OK");
                        Toast toastYes = Toast.makeText(MainActivity.this,
                                "Нажата кнопка OK", Toast.LENGTH_LONG);
                        toastYes.show();
                        break;
                    case R.id.btnNo:
                        tvOut.setText("Нажата кнопка Cancel");
                        Toast toastNo = Toast.makeText(MainActivity.this,
                                "Нажата кнопка Cancel", Toast.LENGTH_SHORT);
                        toastNo.show();
                        break;
                }
            }
        };
    }
}
