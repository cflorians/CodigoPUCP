import java.util.ArrayList;

public class Libreria {
    private String nombre;
    private String direccion;
    private final ArrayList<Libro> libros;
    private final ArrayList<Cliente> clientes;
    private int cantidadVendida;
    double totalVendido;

    public Libreria() {
        libros = new ArrayList<>();
        clientes = new ArrayList<>();
        cantidadVendida = 0;
        totalVendido = 0;
    }
}
