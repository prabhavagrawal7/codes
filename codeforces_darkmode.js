darkmode.js
document.documentElement.style.filter = "invert(0.9)"

rated_class = document.querySelectorAll("[class^=rated]")
function getValue(elem, property) {
    return window.getComputedStyle(elem, null).getPropertyValue(property);
}
function convertColor(color) {
    var regex = /\d+/g;
    var string = color;
    var matches = string.match(regex);  // creates array from matches
    for (let i = 0; i < 3; i++)
        matches[i] = Math.round(parseInt((matches[i]) * 3 + 255) / 4)
    rtn = `color: rgb(${matches[0]}, ${matches[1]}, ${matches[2]}) !important`
    return rtn;
}
for (let i = 0; i < rated_class.length; ++i) {
    var backgroundColor = getValue(rated_class[i], "color");
    let newcolor = convertColor(backgroundColor);
    rated_class[i].setAttribute('style', newcolor);
    rated_class[i].setAttribute('style', newcolor);
    rated_class[i].style.filter = "invert(0.9)"
}
all_canvas = document.querySelectorAll("canvas")
for (let i = 0; i < all_canvas.length; ++i) {
    all_canvas[i].style.filter = "invert(0.9)"
}
legendary_fix = document.querySelectorAll(".legendary-user-first-letter")
for (let i = 0; i < legendary_fix.length; ++i) {
    legendary_fix[i].style.filter = "invert(0.9)"

}



// $('.user-green').css('color', '#!important')