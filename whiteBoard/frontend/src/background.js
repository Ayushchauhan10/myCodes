// In background.js
chrome.runtime.onMessage.addListener(function(message, sender, sendResponse) {
    if (message.action === "change_p_tags") {
        // Send a message to content.js
        chrome.tabs.query({active: true, currentWindow: true}, function(tabs) {
            chrome.tabs.sendMessage(tabs[0].id, {action: "change_p_tags", newText: message.newText});
        });
    }
});
