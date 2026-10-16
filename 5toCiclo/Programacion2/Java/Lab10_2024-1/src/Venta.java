import java.util.Scanner;

public class Venta {
    private int dni;
    private int clasificacion;
    private int fecha; //aaaammdd

    public Venta() {
        dni = 0;
    }

    public int getDni() {
        return dni;
    }

    public void setDni(int dni) {
        this.dni = dni;
    }

    public int getClasificacion() {
        return clasificacion;
    }

    public void setClasificacion(int clasificacion) {
        this.clasificacion = clasificacion;
    }

    public int getFecha() {
        return fecha;
    }

    public void setFecha(int fecha) {
        this.fecha = fecha;
    }

    public boolean leer(Scanner arch){
        if (!arch.hasNext()) return false;

        // MVU0233   11750801   6   9   2023   5
        // codLibro  dni       dd  mm   aaaa  clasificacion
        int dd, mm , aa;



        return true;
    }
}
