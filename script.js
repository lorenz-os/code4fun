const AudioContext = window.AudioContext || window.webkitAudioContext;

// Erzeugen eines neuen AudioContext-Objekts
const audioContext = new AudioContext();

// Zugriff auf den HTML Tag Audio
const audioElement = document.getElementById("myAudio");

// Erstellung eines Mediaelements abhängig von Quelle
const track = audioContext.createMediaElementSource(audioElement);

// Track wird verbudnen mit der default Ausgabe des Browsers
track.connect(audioContext.destination);

// Zugriff auf PlayButton
const playButton = document.querySelector("button");

// Event-Listener wird auf PlayButton gelegt, um User-Aktionen abzufangen und entsprechend zu reagieren
playButton.addEventListener(
  "click",
  function () {
    // Überprüfung des Zustands vom AudioContext (wegen Autoplay)
    if (audioContext.state === "suspended") {
      audioContext.resume();
    }

    // Spielt den Track ab oder stoppt ihn je nach aktuellem Zustand
    if (this.dataset.playing === "false") {
      audioElement.play();
      this.dataset.playing = "true";
    } else if (this.dataset.playing === "true") {
      audioElement.pause();
      this.dataset.playing = "false";
    }
  },
  false
);

// Wenn Abspielen fertig, dann Zustand von dataset.playing wieder auf false
audioElement.addEventListener(
  "ended",
  () => {
    playButton.dataset.playing = "false";
  },
  false
);
//------------------------------------------------------------------------------------------
// Erstellen eines Analysers, der mit dem Audiodatei verbunden wird
var analyser = audioContext.createAnalyser();
track.connect(analyser);

// Erstellen eines Arrays, in dem zum aktuellen Zeitpunkt Daten der eingehenden Audiodatei gespeichert werden
analyser.fftSize = 2048;
var bufferLength = analyser.frequencyBinCount;
var dataArray = new Uint8Array(bufferLength);
analyser.getByteTimeDomainData(dataArray);
//------------------------------------------------------------------------------------------
// Erstellen des Canvas, durch Zugriff auf die ID
var canvas = document.getElementById("oscilloscope");
var canvasCtx = canvas.getContext("2d");

// Zeichnen eines Canvas zur Visualisierung der Frequenzen
function draw() {
  var drawVisual = requestAnimationFrame(draw);

  analyser.getByteTimeDomainData(dataArray);

  canvasCtx.fillStyle = "rgb(240,128,128)";
  canvasCtx.fillRect(0, 0, canvas.width, canvas.height);

  canvasCtx.lineWidth = 2;
  canvasCtx.strokeStyle = "rgb(50, 150, 127)";

  canvasCtx.beginPath();

  var sliceWidth = (canvas.width * 1.0) / bufferLength;
  var x = 0;

  for (var i = 0; i < bufferLength; i++) {
    var v = dataArray[i] / 128.0;
    var y = (v * canvas.height) / 2;

    if (i === 0) {
      canvasCtx.moveTo(x, y);
    } else {
      canvasCtx.lineTo(x, y);
    }

    x += sliceWidth;
  }

  canvasCtx.lineTo(canvas.width, canvas.height / 2);
  canvasCtx.stroke();
}

// Ausführen der draw()-Funktion
draw();
