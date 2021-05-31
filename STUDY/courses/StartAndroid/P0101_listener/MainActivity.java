package com.denone.p0101_listener;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    TextView textOut;
    Button buttonOk;
    Button buttonCancel;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Find View-element
        textOut = (TextView) findViewById(R.id.tvOut);
        buttonOk = (Button) findViewById(R.id.btnOk);
        buttonCancel = (Button) findViewById(R.id.btnCancel);

        buttonOk.setOnClickListener(this);
        buttonCancel.setOnClickListener(this);
    }

        public void onClick(View v) {
            // using id recognize the button
            switch (v.getId()) {
                case R.id.btnOk:
                    // button OK
                    textOut.setText("Нажата кнопка ОК");
                    break;
                case R.id.btnCancel:
                    // button Cancel
                    textOut.setText("Нажата кнопка Cancel");
                    break;
            }
    }
}
