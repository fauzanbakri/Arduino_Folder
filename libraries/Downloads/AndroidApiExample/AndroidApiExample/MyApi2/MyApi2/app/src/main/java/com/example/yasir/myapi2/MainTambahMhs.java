package com.example.yasir.myapi2;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.android.volley.AuthFailureError;
import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.VolleyLog;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.UnsupportedEncodingException;

import static android.widget.Toast.LENGTH_SHORT;

public class MainTambahMhs extends AppCompatActivity {

    // buat variable reference
    EditText mNim, mNama, mAlamat;
    private Button mBtnSubmit;

    // inisialisasi url submit
    private final static String URL = "http://10.1.7.74/web3b/simplejson/add.php";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main_tambah_mhs);

        mNim = findViewById(R.id.et_input_nim);
        mNama = findViewById(R.id.et_input_nama);
        mAlamat = findViewById(R.id.et_input_alamat);
        mBtnSubmit = findViewById(R.id.btn_input_submit);

        mBtnSubmit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                String sNim = mNim.getText().toString();
                String sNama = mNama.getText().toString();
                String sAlamat = mAlamat.getText().toString();

                String data = "{"+
                        "\"nama\"" + ":\"" + sNama + "\"," +
                        "\"nim\"" + ":\"" + sNim + "\"," +
                        "\"alamat\"" + ":\"" + sAlamat + "\"" +
                        "}";
                TambahData(data);

                mNim.setText("");
                mNama.setText("");
                mAlamat.setText("");

                Toast.makeText(getApplicationContext(),"Data Inserted",Toast.LENGTH_SHORT).show();

                Intent intent = new Intent(getApplicationContext(),MainActivity.class);
                startActivity(intent);
            }
        });
    }

    private void TambahData(String data){

        // cek masuk method tambah
        Toast.makeText(getApplicationContext(),data,Toast.LENGTH_SHORT).show();

        final String savedata = data;

        RequestQueue mRequestQueue = Volley.newRequestQueue(getApplicationContext());

        StringRequest mStringRequest = new StringRequest(Request.Method.POST, URL, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {

                try {

                    JSONObject addMhsObject = new JSONObject(response);

                    Log.d("APIResponse",addMhsObject.toString());

                } catch (JSONException e) {
                    e.printStackTrace();
                }

            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {

                // tampilkan error log jika ada
                VolleyLog.d("APIError", error.getMessage());

            }
        }){
            @Override
            public String getBodyContentType(){
                return "application/json;charset=utf-8";
            }

            @Override
            public byte[] getBody() throws AuthFailureError{
                try {
                    return savedata == null ? null : savedata.getBytes("utf-8");
                }catch (UnsupportedEncodingException e) {
                    e.printStackTrace();
                    return null;
                }
            }
        };

        mRequestQueue.add(mStringRequest);
    }
}
