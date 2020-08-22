package com.example.yasir.myapi2;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.VolleyLog;
import com.android.volley.toolbox.JsonArrayRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.LinkedList;

public class MainActivity extends AppCompatActivity {

    private final LinkedList<String> mNama = new LinkedList<>();

    private final static String URL = "http://10.1.7.74/web3b/simplejson/read.php";

    private Button mBtnTambah;
    private TextView mTxtDataMhs;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mBtnTambah = findViewById(R.id.btn_getdata);
        mTxtDataMhs = findViewById(R.id.tv_json);

        // prepare queue request
        RequestQueue mRequestQueue = Volley.newRequestQueue(this);

        // membuat query request
        JsonArrayRequest arrayRequest = new JsonArrayRequest(Request.Method.GET, URL, new Response.Listener<JSONArray>() {
            @Override
            public void onResponse(JSONArray response) {

                // tampilkan hasil respon dalam log
                Log.d("APIRespone", response.toString());

                // looping sebanyak jumlah hasil data
                for(int i=0;i<response.length();i++){
                    try {

                        // setiap hasil dibentung object
                        JSONObject mhsObject = response.getJSONObject(i);

                        // setiap data object ditambah dalam variable array
                        mNama.addLast(mhsObject.getString("nama_mhs"));

                    } catch (JSONException e) {
                        e.printStackTrace();
                    }

                }

                // tampilkan
                Log.d("StringRespone",String.valueOf(mNama));
                mTxtDataMhs.setText(String.valueOf(mNama));

            }
        }, new Response.ErrorListener() {

            // handling error
            @Override
            public void onErrorResponse(VolleyError error) {

                // tampilkan error yang terjadi jika ada
                VolleyLog.d("APIError", error.getMessage());

            }
        });

        // tambah queue eksekusi request
        mRequestQueue.add(arrayRequest);
    }

    public void tambahData(View view) {
        Intent intent = new Intent(this,MainTambahMhs.class);
        startActivity(intent);
    }
}
