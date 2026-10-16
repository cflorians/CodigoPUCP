import java.util.ArrayList;
import java.util.Scanner;

public class Usuario {
    private int id;
    private String nombreCompleto;
    private int dni;
    private int edad;
    private String ciudad;
    private String fechaNacimiento;
    private long telefono;
    private String correo;
    private String especialidad;
    private final ArrayList<Suscripcion> suscripciones;

    public ArrayList<Suscripcion> getSuscripciones() {
        return suscripciones;
    }

    public Usuario(){
        this.suscripciones = new ArrayList<>();
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNombreCompleto() {
        return nombreCompleto;
    }

    public void setNombreCompleto(String nombreCompleto) {
        this.nombreCompleto = nombreCompleto;
    }

    public int getDni() {
        return dni;
    }

    public void setDni(int dni) {
        this.dni = dni;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public String getCiudad() {
        return ciudad;
    }

    public void setCiudad(String ciudad) {
        this.ciudad = ciudad;
    }

    public String getFechaNacimiento() {
        return fechaNacimiento;
    }

    public void setFechaNacimiento(String fechaNacimiento) {
        this.fechaNacimiento = fechaNacimiento;
    }

    public long getTelefono() {
        return telefono;
    }

    public void setTelefono(long telefono) {
        this.telefono = telefono;
    }

    public boolean leer(Scanner arch){
        if (!arch.hasNextInt()) return false;

        this.id = arch.nextInt();
        this.nombreCompleto = arch.next();
        this.dni = arch.nextInt();
        this.edad = arch.nextInt();
        this.ciudad = arch.next();
        this.fechaNacimiento = arch.next();
        this.telefono = arch.nextLong();
        this.correo = arch.next();
        this.especialidad = arch.next();

        return true;
    }

    public double calcularCosto(){
        double costo = 0.0;
        for (Suscripcion sub : suscripciones){
            costo += sub.calcularPrecio();
        }
        return costo;
    }

    @Override
    public String toString() {
        return String.format("%-4s %-20s %-12s %-12s %-12s %-12s %-12s %-22s %-20s",
                id, nombreCompleto, dni, edad, ciudad, fechaNacimiento, telefono, correo, especialidad);
    }

    public void imprimir(){
        System.out.println(this);
        System.out.println("     Suscripciones: ");
        for (Suscripcion sub : suscripciones){
            // falta impresion de suscripciones
        }
    }
}
