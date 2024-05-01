// document.addEventListener('DOMContentLoaded', function() {
//     const backgroundColorPicker = document.getElementById('backgroundColorPicker');
  
//     backgroundColorPicker.addEventListener('input', function(event) {
//       const color = event.target.value;
//       chrome.tabs.query({ active: true, currentWindow: true }, function(tabs) {
//         chrome.tabs.sendMessage(tabs[0].id, { action: 'changeFontColor', color: color });
//       });
//     });

//     const markerIcon = document.querySelector('.marker');

//     markerIcon.addEventListener('click', () => {
//       const div2 = document.querySelector('.div2');
//       div2.textContent = 'Pen';
//     });
// });



// In popup.js
document.getElementById('updateButton').addEventListener('click', function() {
  var newText = document.getElementById('textInput').value;
  chrome.runtime.sendMessage({action: "change_p_tags", newText: newText});
});


