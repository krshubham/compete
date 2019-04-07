package com.he.api;

import java.util.Collection;
import java.util.HashMap;
import java.util.UUID;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import java.io.*;
import org.w3c.dom.*;
import javax.xml.parsers.*;
import javax.xml.transform.*;
import javax.xml.transform.dom.*;
import javax.xml.transform.stream.*;  

@WebServlet("/API")
public class APIServlet extends HttpServlet {
    @Override
    public void doGet(HttpServletRequest req, HttpServletRequest res)
    throws IOException, ServletException{
        PrintWriter out = res.getWriter();
        try {
            String action = req.getParameter("action");
            if(action.equals("searchById")){
                String 
            }
            else if(action.equals("searchByFirstName")){

            }
            else if(action.equal("updateUser")){

            }
            else if(action.equals("insertUser")){

            }
        }
        catch(Exception e){

        }
    }
}