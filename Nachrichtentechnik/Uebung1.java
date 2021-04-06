import java.lang.Math;

public class Uebung1 {

    // Klassenattribut Schlüssel initalisiert, wird im Konstruktor gesetzt
    private int key;
    private int key2;

    public static void main(String[] args) {
        // Aufgabe 1) Häufigkeiten und Informationsgehalt

        String encrypt = "wosx lkew\r\n\r\nsmr rkmudo, qbel exn zvkqdo wsmr,\r\nnkxx gkb wosx lkew qocodjd.\r\nnob xkmrlkb ukw exn pbkqdo wsmr.\r\n\"osx lsbxlkew scd oc! ckqdo smr\".\r\nexn todjd?\r\n\r\nqsxq wkxmrob gsxdobcdebw fyblos.\r\nwosx lkew cdord pocd sw qbexn.\r\nob lveordo nsococ tkrb sw wks,\r\nnso lsoxox pvyqox gosd roblos!\r\ntk, exn?\r\n\r\nnso cyxxo cmrsox, smr vsop rsxkec\r\nexn ckr nso lveodox kx\r\nexn wkvdo wsb nso lsbxox kec\r\nexn nkmrdo kx nox obxdocmrwkec!\r\nexn nkxx?\r\n\r\ndbeq lkvn osx ukvdob boqoxcmrgkvv\r\nnso lveodoxzbkmrd nkfyx.\r\nnymr sx nox jszpovuovmrox kvv\r\nckcc pocd osx uvosxob, qbeoxob lkvv!\r\nexn cmryx\r\n\r\ngkb texs nk exn tevs ew\r\nexn ukw keqecd exn qsxq.\r\nnk vsop smr ew lkew robew\r\nexn ckr- exn ckr- lsx smr noxx neww?-,\r\nnkcc ob fyvv kozpov rsxq!";
        String decrypt = "mein baum\r\n\r\nich hackte, grub und plagte mich,\r\ndann war mein baum gesetzt.\r\nder nachbar kam und fragte mich.\r\n\"ein birnbaum ist es! sagte ich\".\r\nund jetzt?\r\n\r\nging mancher wintersturm vorbei.\r\nmein baum steht fest im grund.\r\ner bluehte dieses jahr im mai,\r\ndie bienen flogen weit herbei!\r\nja, und?\r\n\r\ndie sonne schien, ich lief hinaus\r\nund sah die blueten an\r\nund malte mir die birnen aus\r\nund dachte an den ernteschmaus!\r\nund dann?\r\n\r\ntrug bald ein kalter regenschwall\r\ndie bluetenpracht davon.\r\ndoch in den zipfelkelchen all\r\nsass fest ein kleiner, gruener ball!\r\nund schon\r\n\r\nwar juni da und juli um\r\nund kam august und ging.\r\nda lief ich um baum herum\r\nund sah- und sah- bin ich denn dumm?-,\r\ndass er voll aepfel hing!";

        String kleinerText1 = encrypt.toLowerCase(); // Großbuchstaben zu Kleinbuchstaben
        String trimText1 = kleinerText1.replaceAll(" ", ""); // Leerzeichen + LeerString entfernen
        char[] alphabet = "abcdefghijklmnopqrstuvwxyz".toCharArray(); // Array mit allen Buchstaben
        double[] erg = new double[26]; // Platzhalter-Array für Buchstabenhäufigkeit

        System.out.println("\n" + "Anzahl aller Buchstaben: " + alleBuchstaben(trimText1)); // Anzahl aller Buchstaben im Text wird geprinted

        absoluteHäufigkeit(trimText1, alphabet, erg); // berechnet die absolute Häufigkeit von einem bestimmten Buchstaben und wird ausgegeben
        relativeHäufigkeit(trimText1, alphabet, erg); // berechnet die relative Häufigkeit von einem bestimmten Buchstaben und wird ausgegeben
        informationsgehalt(trimText1, alphabet, erg); // berechnet den Informationsgehalt eines jeden Buchstabens und wird ausgegeben

        // ------------------------------------------------------------------------------------------------------------------------

        // Aufgabe2) Caesar Cypher

        Uebung1 cc = new Uebung1(10); // Konstruktor Aufruf mit 10
        System.out.println("\n" + "Wir entschlüsseln mit einer Verschiebung von " + cc.getKey() + "\n"); // gibt den Key mit 10 Stellen aus
        System.out.println(cc.decrypt(encrypt, alphabet));

        Uebung1 cc2 = new Uebung1(16); // Konstruktor Aufruf mit 16
        System.out.println("\n" + "Wir verschlüsseln mit einer Verschiebung von " + cc2.getKey2() + "\n"); // gibt den Key mit 16 Stellen aus
        System.out.println(cc2.encrypt(decrypt, alphabet));
    }

    // Konstruktor setzt den Schlüssel
    public Uebung1(int stellen) {
        this.key = stellen; // Key um X Stellen nach links verschoben
        this.key2 = stellen;
    }

    public static int alleBuchstaben(String encrypt) {

        double counter = 0; // Zählt nur die Buchstaben

        for (int i = 0; i < encrypt.length(); i++) {
            if (Character.isLetter(encrypt.charAt(i))) { // Abfrage ob Buchstabe
                counter++;
            }
        }
        return (int) counter;
    }

    public static double[] absoluteHäufigkeit(String encrypt, char[] alphabet, double[] erg) {

        double count = 0;
        for (int i = 0; i < alphabet.length; i++) { // Zählt Alphabet durch
            for (int x = 0; x < encrypt.length(); x++) { // Geht Text durch
                if (encrypt.charAt(x) == alphabet[i]) { // Wenn an Stelle x gleich an Stelle dann Zählen wir eins hoch
                    count++;
                }
            }
            erg[i] = count; // Array an der Stelle überschreiben
            count = 0; // Zurücksetzen für neuen Buchstaben
        }
        System.out.println("\n" + "Absolute Häufigkeit:");
        for (int j = 0; j < alphabet.length; j++) {
            System.out.println(alphabet[j] + ": " + (int) erg[j]); // Printed den Buchstaben aus dem Alphabet-Array mit der dazugehörigen Häufigkeit
        }
        return erg;
    }

    public static double[] relativeHäufigkeit(String encrypt, char[] alphabet, double[] erg) {
        double counter = alleBuchstaben(encrypt);
        for (int i = 0; i < erg.length; i++) { // Geht alle Buchstaben im Array durch
            erg[i] /= counter; // FORMEL: Absolute Häufigkeit des Buchstaben (vom Array) / gesamte Anzahl der Buchstaben
        }
        System.out.println("\n" + "Relative Häufigkeit:");
        for (int j = 0; j < alphabet.length; j++) {
            System.out.println(alphabet[j] + ": " + erg[j]); // Printed den Buchstaben aus dem Alphabet-Array mit der dazugehörigen Häufigkeit
        }
        return erg;
    }

    public static double[] informationsgehalt(String encrypt, char[] alphabet, double[] erg) {
        for (int i = 0; i < erg.length; i++) {
            if (erg[i] == 0) { // Fragt ob Ergebnis an Stelle i = 0
                erg[i] = 0; // Falls ja -> auf 0 gesetzt (alternativ könnte man auch continue benutzen)
            } else {
                erg[i] = Math.log((1 / erg[i])) / Math.log(2); // Formel: vom Blatt mit der Log2-Berechnung
            }
        }
        System.out.println("\n" + "Informationsgehalt:");
        for (int j = 0; j < alphabet.length; j++) {
            if (erg[j] == 0) {
                System.out.println(alphabet[j] + ": " + "nicht lösbar"); // Durch "Infinity" ersetzt (erzeugt besser lesbare Ausgabe)
                continue;
            }
            System.out.println(alphabet[j] + ": " + erg[j]); // Printed den Buchstaben aus dem Alphabet-Array mit dem dazugehörigen Informationsgehalt
        }
        return erg;
    }

    public String decrypt(String encrypt, char[] alphabet) {
        char[] resultat = encrypt.toCharArray(); // Text wird in ein Char Array umgewandelt, um im Anschluss besser darüber iterieren zu können
        if (this.key == 0) {
            return encrypt; // wenn der Text im Cypher um keine Position verschoben wurde, geben wir den ursprünglichen Text zurück
        }
        for (int i = 0; i < resultat.length; i++) { // iterieren über das Char Array (enthält Text)
            for (int k = 0; k < alphabet.length; k++) { // iterieren über das Alphabet
                if (resultat[i] == alphabet[k]) { // an welcher Stelle steht der Buchstabe resultat[i] im Alphabet?
                    if ((k - this.key) < 0) { // Suche nach um "this.key" (in dem Fall 10) verschobenen Stellen von resultat[i] (wenn Rechnung ins Negative verläuft, dann wird der Rest vom Ende des Alphabets abgezogen)
                        k = 26 - Math.abs(k - this.key);
                        resultat[i] = alphabet[k]; // Entschlüsselung und dementsprechende Überschreibung des Originaltextes
                    } else {
                        resultat[i] = alphabet[k - this.key]; // gehen im Alphabet einfach um "this.key" (in dem Fall 10) Stellen nach rechts/links und überschreiben Originaltext
                    }
                }
            }
        }
        String resultatString = new String(resultat); // Ergebnis wird im neuen String gespeichert
        return resultatString;
    }

    public String encrypt(String decrypt, char[] alphabet) { // selbes Prinzip
        char[] ergebnis = decrypt.toCharArray();
        if (this.key2 == 0) {
            return decrypt;
        }
        for (int i = 0; i < ergebnis.length; i++) {
            for (int k = 0; k < alphabet.length; k++) {
                if (ergebnis[i] == alphabet[k]) {
                    if ((k - this.key2) < 0) {
                        k = 26 - Math.abs(k - this.key2);
                        ergebnis[i] = alphabet[k];
                    } else {
                        ergebnis[i] = alphabet[k - this.key2];
                    }
                }
            }
        }
        String ergebnisString = new String(ergebnis);
        return ergebnisString;
    }

    // Ruft den Schlüssel (Klassenattribut) ab
    public int getKey() {
        return this.key;
    }

    public int getKey2() {
        return this.key2;
    }
}