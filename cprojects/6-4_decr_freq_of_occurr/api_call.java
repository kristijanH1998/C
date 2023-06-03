package com.example.userfriendlycalculator;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
//author:Kristijan
//source: https://www.youtube.com/watch?v=qzRKa8I36Ww


public class api_call {

    public static String result = "";

    private static HttpURLConnection connection;
    public static void main (String[] args){

    }

    public static String returnResult (String input){
        BufferedReader reader;
        String line = "";
        StringBuffer responseContent = new StringBuffer();

        try {
            URL myurl = new URL("http://api.wolframalpha.com/v1/result?appid=XL554J-39UTLQWJTV&i=" + input);
            connection = (HttpURLConnection) myurl.openConnection();
            connection.setRequestMethod("GET");
            connection.setConnectTimeout(5000);
            connection.setReadTimeout(5000);

            int status = connection.getResponseCode();


            if(status>299){
                reader = new BufferedReader (new InputStreamReader(connection.getErrorStream()));
                while ((line = reader.readLine()) != null){
                    responseContent.append(line);
                }
                reader.close();
            } else {
                reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
                while ((line = reader.readLine()) != null){
                    responseContent.append(line);
                }
                reader.close();
            }


        } catch(MalformedURLException exception){
            exception.printStackTrace();
        } catch(IOException exception2){
            exception2.printStackTrace();
        } finally {
            connection.disconnect();
        }
        result = responseContent.toString();
        return(result);

    }

}
