// CANVAS Objekte holen und Variablen zuweisen
var canvas = document.getElementById("firstCanvas");
var canvas1 = document.getElementById("secondCanvas");
var canvas2 = document.getElementById("thirdCanvas");
var canvas3 = document.getElementById("fourthCanvas");
var canvas4 = document.getElementById("fifthCanvas");
// CANVAS wird dem Context zugeordnet
var context = canvas.getContext("2d");
var context1 = canvas1.getContext("2d");
var context2 = canvas2.getContext("2d");
var context3 = canvas3.getContext("2d");
var context4 = canvas4.getContext("2d");
// Bild Objekt wird erstellt
let img = new Image();
let img1 = new Image();
let img2 = new Image();
let img3 = new Image();
let img4 = new Image();
// Definieren der Höhe und Breite des Canvas
var h = 1700;
var w = 1150;
// Funktion die schaut, ob das Bild bereits geladen ist und zeichnet sie dann auf den CANVAS  --> für kleinere Images (img.width / 2, img.height / 2)
img.onload = function () {
  context.drawImage(img, 25, 25);
  console.log("Daten vom ersten CANVAS:  \n");
  console.log(getAverageColor(img, context));
  var rgb = getAverageColor(img, context);
  setColor("firstCanvas", rgb);
  console.log("\n");
};
img1.onload = function () {
  context1.drawImage(img1, 25, 25);
  console.log("Daten vom zweiten CANVAS:  \n");
  console.log(getAverageColor(img1, context1));
  var rgb1 = getAverageColor(img1, context1);
  setColor("secondCanvas", rgb1);
  console.log("\n");
};
img2.onload = function () {
  context2.drawImage(img2, 25, 25);
  console.log("Daten vom dritten CANVAS:  \n");
  console.log(getAverageColor(img2, context2));
  var rgb2 = getAverageColor(img2, context2);
  setColor("thirdCanvas", rgb2);
  console.log("\n");
};
img3.onload = function () {
  context3.drawImage(img3, 46, 7);
  console.log("Daten vom vierten CANVAS:  \n");
  console.log(getAverageColor(img3, context3));
  var rgb3 = getAverageColor(img3, context3);
  setColor("fourthCanvas", rgb3);
  console.log("\n");
};
img4.onload = function () {
  context4.drawImage(img4, 25, 25);
  console.log("Daten vom fünften CANVAS:  \n");
  console.log(getAverageColor(img4, context4));
  var rgb4 = getAverageColor(img4, context4);
  setColor("fifthCanvas", rgb4);
  console.log("\n");
};

// Ändern der Hintergrundfarbe des Canvas durch die Average Color
function setColor(canvasID, rgbRef) {
  var rgbStr = "rgb(" + rgbRef.r + ", " + rgbRef.g + ", " + rgbRef.b + ")";
  var canvasBckgrColor = document.getElementById(canvasID);
  canvasBckgrColor.style.backgroundColor = rgbStr;
}

// Bilddateien werden hier geladen
img.src = "images/Berg.jpeg";
img1.src = "images/Rose.jpeg";
img2.src = "images/Tanne.jpeg";
img3.src = "images/Wald.jpeg";
img4.src = "images/Wasser.jpeg";

// Average Color bekommen
function getAverageColor(img, context) {
  var h = 1650;
  var w = 1100;

  var imageData = context.getImageData(0, 0, w, h);
  var data = imageData.data;
  var r = 0;
  var g = 0;
  var b = 0;

  // Schleife geht über jeden Pixel des Arrays drüber und addiert
  for (var i = 0; i < data.length; i += 4) {
    r += data[i]; // erster Farbwert ist rot
    g += data[i + 1]; // zweiter Farbwert ist grün
    b += data[i + 2]; // dritter Farbwert ist blau
  }
  // bildet den Durchschnitt: Summe der Farbwerte durch die Anzahl an Pixeln pro Farbe
  // nur durch drei teilen, da wir nur drei Farben (rot, grün, blau) haben
  r = Math.floor(r / (data.length / 4));
  g = Math.floor(g / (data.length / 4));
  b = Math.floor(b / (data.length / 4));

  colorArr = { r: r, g: g, b: b };
  return colorArr;
}
