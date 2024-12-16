const express = require("express");

const app=express();

const fs=require("fs");

const users=require("./MOCK_DATA.json");

const { type } = require("os");

const { default: mongoose } = require("mongoose");

const { timeStamp } = require("console");

const userRouter=require("./Routes/user");

const User=require("./Models/User");

const {connectMongoDb}=require("./Connections");

connectMongoDb("mongodb://127.0.0.1:27017/youtube-app-1");

app.use(express.urlencoded({extended:false}));

app.use("/user",userRouter);
app.listen(3002,()=>{
    console.log("serveer is running on port 3002");
});

