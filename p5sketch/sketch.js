console.log("Inside sketch.js")


  
chrome.runtime.onMessage.addListener(function(message, sender, sendResponse) {
    if (message.action === "executeCode") {
      const s = ( sketch ) => {
          
          sketch.setup=function(){
              console.log("inside setup")
              document.body.style['userSelect']='none';
              let w=sketch.windowWidth;
              let h=sketch.windowHeight;
              // let h= Math.max( document.body.scrollHeight, document.body.offsetHeight, 
              //     document.documentElement.clientHeight, document.documentElement.scrollHeight, document.documentElement.offsetHeight );
              let c=sketch.createCanvas(w,h);
              c.position(0,0);
              c.style('pointer-events', 'none');
              c.style('z-index', '999');
              sketch.clear();
          }
          
          sketch.draw=function(){
              console.log("inside draw");
              sketch.stroke(4);
              sketch.strokeWeight(4);
              if (sketch.mouseIsPressed) {
                
                    // Draw with current stroke
                    sketch.line(sketch.mouseX, sketch.mouseY, sketch.pmouseX, sketch.pmouseY);
                
            }
          }
          
      };
      
      let myp5 = new p5(s);
      
     
    }
  });
  

