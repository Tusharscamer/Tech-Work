const mongoose=require("mongoose")
const usersSchema=new mongoose.Schema({
    firstName:{
        type :String,
        required:true
    },
    lastName :{
        type : String,
    },
    email :{
        type : String,
        required : true,
        unique : true
    },
    gender :{
        type : String,
        required : true
    },
}
);
const User= mongoose.model("users",usersSchema)
module.exports=User;