public class DCT {
    // Matrizen erstellen
    private static int[][] matrixA = { { 107, 109, 115, 107, 113, 115, 115, 113 }, { 24, 24, 24, 8, 16, 8, 16, 20 },
            { 16, 24, 16, 16, 24, 16, 16, 24 }, { 16, 28, 16, 16, 28, 16, 24, 32 }, { 16, 28, 24, 24, 32, 24, 24, 36 },
            { 24, 28, 24, 24, 28, 24, 24, 28 }, { 16, 20, 16, 16, 28, 16, 24, 32 }, { 8, 12, 8, 8, 8, 8, 8, 8 } };

    private static int[][] matrixB = { { 123, 121, 123, 123, 125, 123, 123, 125 }, { 66, 65, 66, 16, 16, 16, 16, 20 },
            { 28, 24, 24, 32, 24, 24, 32, 24 }, { 32, 24, 24, 32, 24, 24, 32, 24 }, { 32, 24, 24, 36, 33, 24, 36, 33 },
            { 36, 33, 24, 36, 33, 24, 32, 24 }, { 24, 16, 16, 28, 16, 33, 44, 33 }, { 16, 16, 20, 16, 16, 20, 8, 16 } };

    private static int[][] matrixC = { { 139, 144, 149, 153, 155, 155, 155, 155 },
            { 144, 151, 153, 156, 159, 156, 156, 156 }, { 150, 155, 160, 163, 158, 156, 156, 156 },
            { 159, 161, 162, 160, 160, 159, 159, 159 }, { 159, 160, 161, 162, 162, 155, 155, 155 },
            { 161, 161, 161, 161, 160, 157, 157, 157 }, { 162, 162, 161, 163, 162, 157, 157, 157 },
            { 162, 162, 161, 161, 163, 158, 158, 158 } };

    private static int[][] matrixD = { { 197, 208, 226, 198, 209, 227, 197, 210 },
            { 197, 208, 226, 198, 209, 227, 197, 208 }, { 197, 209, 225, 199, 207, 226, 200, 208 },
            { 197, 208, 226, 198, 209, 227, 197, 208 }, { 196, 209, 225, 199, 207, 226, 199, 208 },
            { 197, 209, 225, 197, 208, 226, 197, 209 }, { 196, 209, 225, 197, 208, 226, 197, 209 },
            { 197, 209, 225, 197, 208, 226, 197, 209 } };

    // Berechnet die eigentliche DCT nach der Formel
    public static int matrixValue(double u, double v, int[][] matrix) {
        double result = 0.0d;
        double sum = 0.0d;
        for (int j = 0; j < matrix.length; j++) {
            for (int k = 0; k < matrix.length; k++) {
                sum = sum + (matrix[j][k] * Math.cos((2 * j + 1) * u * Math.PI / 16))
                        * Math.cos((2 * k + 1) * v * Math.PI / 16);
            }
        }
        result = Math.round((1.0d / 4) * C(u) * C(v) * sum);
        return (int) result;
    }

    // Schreibt die Ergebnisse der DCT in die neue Matrix
    public static int[][] compute(int[][] matrix) {
        int transMatrix[][] = new int[8][8];
        long timeBeforeCompute = System.nanoTime();
        for (int u = 0; u < matrix.length; u++) {
            for (int v = 0; v < matrix.length; v++) {
                transMatrix[u][v] = matrixValue(u, v, matrix);
                System.out.print(Math.round(transMatrix[u][v]) + " ");
            }
            System.out.println("");
        }
        long timeAfterCompute = System.nanoTime();
        long time = (timeAfterCompute - timeBeforeCompute) / 1000000;
        System.out.println("Die Kompression dauerte: " + time + " Millisekunde(n)");
        return transMatrix;
    }

    // Überprüft, ob der Vorfaktor "1 durch Wurzel 2" oder 1 ist
    public static double C(double x) {
        if (x == 0) {
            return (1 / Math.sqrt(2));
        } else {
            return 1.0d;
        }
    }

    public static void main(final String[] args) {
        System.out.println("Berecne die Matrizen!");
        // Methodenaufruf der DCT
        System.out.println("\n");
        compute(matrixA);
        System.out.println("\n");
        compute(matrixB);
        System.out.println("\n");
        compute(matrixC);
        System.out.println("\n");
        compute(matrixD);
    }
}