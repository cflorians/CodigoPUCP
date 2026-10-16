import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Plataforma {

    private final ArrayList<Usuario> usuarios;
    private final ArrayList<Canal> canales;
    private final ArrayList<Suscripcion> suscripciones;

    private final Scanner arch;


    public Plataforma(String nombreArch) throws FileNotFoundException {
        this.usuarios = new ArrayList<>();
        this.canales = new ArrayList<>();
        this.suscripciones = new ArrayList<>();
        this.arch = new Scanner(new File(nombreArch));
    }

    public void cargarDatos(){
        // cargarCanales();
        cargarUsuarios();
        // cargarSubcategorias();
    }

    public void cargarCanales(){
        while (this.arch.hasNext()){
            Canal canal = new Canal();
            if (!canal.leer(arch)) {
                arch.next();
                break;
            }
            canales.add(canal);
        }
    }

    public void cargarUsuarios(){
        while(arch.hasNext()){
            Usuario usuario = new Usuario();
            if (!usuario.leer(arch)) {
                arch.next();
                break;
            }
            usuarios.add(usuario);
        }
    }

    public void cargarSubcategorias(){
        while (arch.hasNext()){
            String tipo = arch.next();
            Suscripcion sub;
            switch (tipo) {
                case "BASICA":
                    sub = new SuscripcionBasica();
                    break;
                case "PREMIUM":
                    sub = new SuscripcionPremium();
                    break;
                default:
                    sub = new SuscripcionVIP();
            }
            if(!sub.leer(arch)) break;

            Usuario usuario = buscarUsuario(sub.getIdUsuario());
            sub.setUsuario(usuario);

            Canal canal = buscarCanal(sub.getIdCanal());
            sub.setCanal(canal);

            usuario.getSuscripciones().add(sub);
            suscripciones.add(sub);
        }
    }

    public Usuario buscarUsuario(int id){
        for (Usuario usuario : usuarios){
            if (id == usuario.getId()) return usuario;
        }
        return null;
    }

    public Canal buscarCanal(int id){
        for (Canal canal : canales){
            if (id == canal.getId()) return canal;
        }
        return null;
    }

    private Scanner getArch() {
        return arch;
    }

    public void imprimirReporte(){
        System.out.println("=".repeat(140));
        System.out.println(" ".repeat(60) + "REPORTE DE USUARIOS");
        System.out.println("=".repeat(140));
        System.out.format("%-4s %-20s %-12s %-12s %-12s %-12s %-12s %-22s %-20s%n",
                          "ID", "Nombre completo", "DNI", "Edad", "Ciudad", "F. Nac.",
                          "Telefono", "Email", "Ocupacion");
        for (Usuario usuario : usuarios){
            usuario.imprimir();
        }
    }
}
