package com.denone.p0091_onclickbuttons;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    TextView tvOut;
    Button btnOk;
    Button btnCancel;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //find all View-elements
        tvOut = (TextView) findViewById(R.id.tvOut);
        btnOk = (Button) findViewById(R.id.btnOk);
        btnCancel = (Button) findViewById(R.id.btnCancel);

        // create a click handler
        View.OnClickListener oclBtnOk = new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // Chenge the text in TextView (tvOut)
                tvOut.setText("Нажата кнопка ОК");
            }
        };
        // assign a handler to the button OK (btnOk)
        btnOk.setOnClickListener(oclBtnOk);

        View.OnClickListener oclBtnCancel = new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // Change text in TextView (tvOut)
                tvOut.setText("Нажата кнопка Cancel");
            }
        };
        // assign a handler to the button Cancel
        btnCancel.setOnClickListener(oclBtnCancel);
    }
}
