// chrome.runtime.onMessage.addListener(function(message, sender, sendResponse) {
//     var paragraphs = document.querySelectorAll("p");
//     for (var i = 0; i < paragraphs.length; i++) {
//       paragraphs[i].textContent = message.content;
//       paragraphs[i].style.color = message.color;
//     }
//   });

  
  chrome.runtime.onMessage.addListener(function(message, sender, sendResponse) {
    if (message.action === "executeCode") {
      var paragraphs = document.querySelectorAll("p");
      for (var i = 0; i < paragraphs.length; i++) {
        paragraphs[i].textContent = message.content;
        paragraphs[i].style.color = '#00ff00';
      }
     
    }
  });
  