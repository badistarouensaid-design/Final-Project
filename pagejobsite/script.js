// initialiser la connexion avec adafruit
const IO = new AdafruitIO("XXX", "XXX");

let statusbadis =document.querySelector("#statusbadis"); 
console.log(statusbadis);

// ccc
IO.setLimit(1);

setInterval(function(){
    IO.getData("light", function(data) {
    console.log(data.feed, data.json[0].value);
    if (data.json[0].value > 1000){
        statusbadis.style.backgroundColor ="#00FF00";
        console.log("coucou")
    }else{
        statusbadis.style.backgroundColor ="#FF0000";
    }
    });
}, 4000);




