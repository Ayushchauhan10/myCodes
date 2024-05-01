// // Create a canvas element
// const canvas = document.createElement('canvas');
// let penColor = '#000000';
// canvas.width = window.innerWidth;
// canvas.height = window.innerHeight;

// // Get the 2D context
// const ctx = canvas.getContext('2d');

// // Capture the entire HTML content
// const htmlContent = document.documentElement.outerHTML;

// // Draw the HTML content onto the canvas
// const img = new Image();
// img.onload = function() {
//   ctx.drawImage(img, 0, 0, canvas.width, canvas.height);
//   document.body.appendChild(canvas);

//   // Enable drawing on the canvas
//   enableDrawing();
// };

// // Convert the HTML content to a data URL and set it as the image source
// img.src = 'data:text/html;base64,' + btoa(htmlContent);

// function enableDrawing() {
//   let isDrawing = true;

//   canvas.addEventListener('mousedown', startDrawing);
//   canvas.addEventListener('mousemove', draw);
//   canvas.addEventListener('mouseup', stopDrawing);

//   canvas.addEventListener('touchstart', startDrawing);
//   canvas.addEventListener('touchmove', draw);
//   canvas.addEventListener('touchend', stopDrawing);

//   function startDrawing(e) {
//     isDrawing = true;
//     draw(e); // Start drawing immediately
//   }

//   function draw(e) {
//     if (!isDrawing) return;

//     // Get the current position of the pointer
//     const x = e.clientX || e.touches[0].clientX;
//     const y = e.clientY || e.touches[0].clientY;

//     // Set up drawing styles
//     ctx.lineWidth = 5;
//     ctx.lineCap = 'round';
//     ctx.strokeStyle = penColor;

//     // Draw on the canvas
//     ctx.lineTo(x, y);
//     ctx.stroke();
//     ctx.beginPath();
//     ctx.moveTo(x, y);
//   }

//   function stopDrawing() {
//     isDrawing = false;
//     ctx.beginPath(); // Reset path
//   }
// }



// chrome.runtime.onMessage.addListener(function(request, sender, sendResponse) {

//     document.body.classList.add('change-font-color');

// });



chrome.runtime.onMessage.addListener(function(message, sender, sendResponse) {
    if (message.action === "change_p_tags") {
        // Change text of all <p> tags
        var pTags = document.querySelectorAll('p');
        pTags.forEach(function(pTag) {
            pTag.textContent = message.newText;
        });
    }
});



