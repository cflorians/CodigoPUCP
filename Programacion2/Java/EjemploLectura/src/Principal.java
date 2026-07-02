import java.io.FileNotFoundException;

public class Principal {
    // NOMBRE: Carlos Florian
    // CODIGO: 20240282
    public static void main(String[] args) throws FileNotFoundException {
        Plataforma plataforma = new Plataforma("datos.txt");

        plataforma.cargarDatos();
        plataforma.imprimirReporte();
    }
}
