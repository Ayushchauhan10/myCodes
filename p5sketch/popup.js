console.log("first")
document.addEventListener("DOMContentLoaded", function() {
    document.getElementById("changeButton").addEventListener("click", function() {
        var newColor = document.getElementById("colorInput").value;
        console.log(newColor) ; 
      chrome.tabs.query({active: true, currentWindow: true}, function(tabs) {
        chrome.tabs.sendMessage(tabs[0].id, {color: newColor});
      });
    });
  });

document.addEventListener("DOMContentLoaded", function() {
    chrome.tabs.query({active: true, currentWindow: true}, function(tabs) {
      var tab = tabs[0];
      chrome.tabs.sendMessage(tab.id, {action: "executeCode"});
    });
  });
  
  