var keyboard = new QwertyHancock({
  id: "keyboard",
  width: 600,
  height: 150,
  octaves: 2,
});

// AudioContext-Objekt wird erzeugt und Zugriff auf Lautstärke wird hergestellt -> dann mit Lautsprechern verbunden
var context = new AudioContext();
masterVolume = context.createGain();

// minimierte Gesamtlautstärke wird an den Lautsprecher weitergegeben
masterVolume.gain.value = 0.3;
masterVolume.connect(context.destination);

// Array oscillators zum Speichern von aktuell verwendeten Oszillatoren
var oscillators = {};

//----------------------- Note wird gespielt ----------------------------
keyboard.keyDown = function (note, frequency) {
  console.log("Note", note, "has been pressed");
  console.log("Its frequency is", frequency);

  // einmaliger Oszillator wird in 'osc' gespeichert
  var osc = context.createOscillator();
  osc2 = context.createOscillator();

  osc.frequency.value = frequency;
  osc2.frequency.value = frequency;

  // Syntharten werden für beide Oszillatoren definiert
  osc.type = "sine";
  osc2.type = "sawtooth";

  osc2.connect(masterVolume);
  osc.connect(masterVolume);

  // Oszillator wird mit den Lautsprechern verbunden
  osc.connect(context.destination);

  // Lautstärke-Gain wird mit den Lautsprechern verbunden
  masterVolume.connect(context.destination);

  // Speichern der aktuellen Oszillatorfrequenz in das Array
  oscillators[frequency] = [osc, osc2];

  // Ton wird für eine Sekunde gehalten
  osc.start(context.currentTime);
  osc2.start(context.currentTime);
  osc.stop(context.currentTime + 1);
  osc2.stop(context.currentTime + 1);

  // leichte Tonveränderung
  osc.detune.value = -10;
  osc2.detune.value = 10;
};

//----------------------- Note wird angehalten ----------------------------
keyboard.keyUp = function (note, frequency) {
  console.log("Note", note, "has been released");
  console.log("Its frequency was", frequency);

  oscillators[frequency].forEach(function (oscillator) {
    oscillator.stop(context.currentTime);
  });
};
