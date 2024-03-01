async function connectspammer() {
  var allqueries = document.querySelectorAll("span");
  // filter out the span elements with text "Connect"
  allqueries = Array.prototype.filter.call(allqueries, function (item) {
    return item.innerText == "Connect";
  });
  let count = 0;
  for (const ele of allqueries) {
    console.log("count = ", count);
    count++;
    ele.click();
    // slow down the script by 2 seconds
    await new Promise((r) => setTimeout(r, 300));
    // send button class name is artdeco-button__text and text is Send
    let sendbutt = document.getElementsByClassName("artdeco-button__text");
    sendbutt = Array.prototype.filter.call(sendbutt, function (item) {
      return item.innerText == "Send without a note";
    });
    // find the send button and click it
    if (sendbutt.length) {
      sendbutt[0].click();
    } else {
      // click the close button
      // button contains data-test-modal-close-btn = "" and aria-label = "Dismiss" and class = artdeco-modal__dismiss
      document.querySelectorAll("button").forEach((element) => {
        if (element.getAttribute("aria-label") == "Dismiss") {
          element.click();
        }
      });
    }
  }
}
function nextPage() {
  document.querySelectorAll("button").forEach((element) => {
    window.scrollTo(0, document.body.scrollHeight);
    if (element.innerText == "Next") {
      element.click();
    }
  });

}
connectspammer();
setInterval(() => {
  connectspammer();
}, 2000);

setInterval(nextPage, 5000);

