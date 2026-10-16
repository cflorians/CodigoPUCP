import java.util.Scanner;

public class Cliente {
    private int dni;
    private String nombre;
    private double totalGastado;

    public Cliente() {
        totalGastado = 0;
    }

    public int getDni() {
        return dni;
    }

    public void setDni(int dni) {
        this.dni = dni;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public double getTotalGastado() {
        return totalGastado;
    }

    public void setTotalGastado(double totalGastado) {
        this.totalGastado = totalGastado;
    }

    public boolean leer(Scanner arch){
        dni = arch.nextInt();
        if (dni == 0) return false;

        nombre = arch.next();

        return true;
    }
}
