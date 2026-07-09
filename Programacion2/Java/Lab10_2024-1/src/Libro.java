import java.util.ArrayList;
import java.util.Objects;
import java.util.Scanner;

public class Libro {
    private String codigo;
    private String titulo;
    private String autor;
    private double precio;
    private final ArrayList<Venta> ventas;
    private int suma;
    private int ranking;
    private double totalVendido;

    public Libro() {
        ventas = new ArrayList<>();
        suma = 0;
        totalVendido = 0;
    }

    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public double getPrecio() {
        return precio;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }

    public int getSuma() {
        return suma;
    }

    public void setSuma(int suma) {
        this.suma = suma;
    }

    public int getRanking() {
        return ranking;
    }

    public void setRanking(int ranking) {
        this.ranking = ranking;
    }

    public double getTotalVendido() {
        return totalVendido;
    }

    public void setTotalVendido(double totalVendido) {
        this.totalVendido = totalVendido;
    }

    // IIM5175   Diamantes_y_pedernales   Jose_Maria_Arguedas   69.02
    public boolean leer(Scanner arch){
            codigo = arch.next();
            if (codigo == "FIN") return false;

            titulo = arch.next();
            autor = arch.next();
            precio = arch.nextDouble();

            return true;
    }
}
