import java.util.Scanner;

public class Canal extends Registro{

    private int id;
    private String nombre;
    private String descripcion;
    private String fechaCreacion;
    private long cantVisualizaciones;
    private String categoria;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    public long getCantVisualizaciones() {
        return cantVisualizaciones;
    }

    public void setCantVisualizaciones(long cantVisualizaciones) {
        this.cantVisualizaciones = cantVisualizaciones;
    }

    public String getCategoria() {
        return categoria;
    }

    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }

    @Override
    public boolean leer(Scanner arch) {
        if (!arch.hasNextInt()) return false;

        this.id = arch.nextInt();
        this.nombre = arch.next();
        this.descripcion = arch.next();
        this.fechaCreacion = arch.next();
        this.cantVisualizaciones = arch.nextLong();
        this.categoria = arch.next();

        return true;
    }

    @Override
    public void imprimir() {
        System.out.println(this);
    }
}
