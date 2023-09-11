setInterval(() => {
  document.querySelectorAll("button").forEach((element) => {
    window.scrollTo(0, document.body.scrollHeight);
    if (element.innerText == "Next") {
      element.click();
    }
  });
}, 7000);
setInterval(() => {
  var allqueries = document.querySelectorAll("span");
  for (const ele of allqueries) {
    if (ele.innerText == "Connect") {
      ele.click();
      sendbutt = document.getElementsByClassName("artdeco-button__text");
      console.log(sendbutt);
      // Code to wait for 1 second, so that modal will appear
      setTimeout(() => {
        for (const send of sendbutt) {
          if (send.innerText == "Send") {
            console.log(send);
            send.click();
          }
        }
      }, 250); // 1000 milliseconds = 1 second
      break;
    }
  }
}, 500);


javascript: (function () {
  // the CSS we are going to inject
  var css = `
    html {
      filter: invert(100%) hue-rotate(120deg) hue-rotate(240deg) hue-rotate(0deg);
    }
  `;

  (head = document.getElementsByTagName("head")[0]),
    (style = document.createElement("style"));

  // a hack, so you can toggle the effect by clicking the bookmarklet again
  if (!window.counter) {
    window.counter = 1;
  } else {
    window.counter++;
    if (window.counter % 2 == 0) {
      var css = `
        html {
          filter: invert(0%);
        }
      `;
    }
  }

  style.type = "text/css";
  if (style.styleSheet) {
    style.styleSheet.cssText = css;
  } else {
    style.appendChild(document.createTextNode(css));
  }

  // injecting the CSS to the head
  head.appendChild(style);
})();
