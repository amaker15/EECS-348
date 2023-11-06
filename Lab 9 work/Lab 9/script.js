function changeColorAndBorder() {
    var rgb = document.getElementById('rgb').value;
    var width = document.getElementById('width').value;
    var text = document.getElementById('text');

    text.style.color = "rgb(" + rgb + ")";
    text.style.borderWidth = width + "px";
}