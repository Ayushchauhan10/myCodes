document.addEventListener("DOMContentLoaded", function() {
    document.getElementById("changeButton").addEventListener("click", function() {
      var newContent = document.getElementById("contentInput").value;
      var newColor = document.getElementById("colorInput").value;
      chrome.tabs.query({active: true, currentWindow: true}, function(tabs) {
        chrome.tabs.sendMessage(tabs[0].id, {content: newContent, color: newColor});
      });
    });
  });

document.addEventListener("DOMContentLoaded", function() {
    chrome.tabs.query({active: true, currentWindow: true}, function(tabs) {
      var tab = tabs[0];
      chrome.tabs.sendMessage(tab.id, {action: "executeCode"});
    });
  });
  