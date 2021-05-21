
function generateRandomColor(){
    r = Math.floor(Math.random() * 256);
    g = Math.floor(Math.random() * 256);
    b = Math.floor(Math.random() * 256);
    return [r, g, b];
}

function randomBackgroundColor() {
    let rgb_colors = generateRandomColor();
    let rgb = `rgb(${rgb_colors[0]}, ${rgb_colors[1]}, ${rgb_colors[2]})`
    document.querySelector('body').style.backgroundColor = rgb;
    document.querySelector('h1').innerText = rgb;
}

let button = document.querySelector("button");
button.addEventListener('click', randomBackgroundColor);
