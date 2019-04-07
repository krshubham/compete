package com.shubham.virtual_lab;

import android.annotation.TargetApi;
...



public class MainActivity extends AppCompatActivity {
    private WebView web;

    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        web = (WebView)findViewById(R.id.webview);

        web.loadUrl("https://www.google.com");
    }
}