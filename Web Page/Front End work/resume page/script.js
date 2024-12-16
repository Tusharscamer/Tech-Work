let modebut=document.querySelector("#mod");
let currentMode="Light";
let body=document.querySelector("body");
modebut.addEventListener('click',()=>{
    if(currentMode==="Light"){
        body.classList.add("dark");
        body.classList.remove("white");
        currentMode="Dark";
    }
    else{
        body.classList.add("white");
        body.classList.remove("dark");
        currentMode="Light";
    }
})