const express=require("express");
const router=express.Router();
router.route("/").get((req,res)=>{
    // always add custom header with X- prefix
    res.setHeader("X-Owner","Tushar");// coustom header
    res.json(users);
    console.log(req.headers);
}).post(async (req, res) => {
    const body = req.body;
    try {
        const result = await User.create({
            firstName: body.first_name,
            lastName: body.last_name,
            email: body.email,
            gender: body.gender,
        });
        console.log(result);
        res.status(201).json({ status: "success", data: result });
    } catch (error) {
        console.error(error);
        res.status(400).json({ status: "error", message: error.message });
    }
});


router.route("/:id")
.get((req,res)=>{
    // getting existing data 
     
    const id=Number(req.params.id);
    const user=users.find((user)=>user.id==id);
    if(!user){
        return res.status(404).json({status:"user not found"});
    }
    res.json(user);
}).patch(async(req,res)=>{
    // updating existing data
    try{
        await User.findByIdAndDelete(req.params.id,{lastName:"Dhakad"});
    }
    catch(err){
        res.status(400).json({status:"error",message:err.message});
    }
}).delete((req,res)=>{
    // delete given data 
    const id=req.params.id;
    const body=req.body;
    const index=users.findIndex((user)=>user.id==id);
    users.splice(index,1)
    console.log("body",body);
    console.log("deleted")
    fs.writeFile("./MOCK_DATA.json", JSON.stringify(users), (err) => {
        res.json({ status: "success", id });
    });
});
module.exports=router;