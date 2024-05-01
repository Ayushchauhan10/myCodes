console.log("Hello from colorChanger");

document.body.style.color = '#808080'; 

let para= document.getElementsByTagName('h1');

for(i of para){
    i.style['background-color']='#808080';
}

document.body.style.backgroundColor = '#808080';
document.documentElement.style.backgroundColor = 'orange';

chrome.runtime.onMessage.addListener(gotResp);

function gotResp(msg,sender,sendResponse) {
    console.log(msg);


}