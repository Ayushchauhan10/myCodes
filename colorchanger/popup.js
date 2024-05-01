document.addEventListener('DOMContentLoaded', function () {
    document.getElementById('changeColorButton').addEventListener('click', changeFontColor);
  });
  
  function setUp(){
    noCanvas();

    let userInput=select('#inputText');
    userInput.input(newText);
    
    chrome.tabs.query({ active: true, currentWindow: true }, newText);


    function newText(){

        function gotTab(tab){
        let messsage=userInput.val();
        let msg={
            txt:"Hello"
        }
        chrome.tabs.sendMessage(tabs[0].id,msg);
    }
  }
}
  function changeFontColor() {
    chrome.tabs.query({ active: true, currentWindow: true }, function (tabs) {
      chrome.tabs.sendMessage(tabs[0].id, { action: 'changeColor' });
    });
  }
  