import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Veterinaria {

    private final ArrayList<Usuario> usuarios;
    private final Scanner arch;


    public Veterinaria(String nombreArch) throws FileNotFoundException {
        this.usuarios = new ArrayList<>();
        this.arch = new Scanner(new File(nombreArch));
    }

    public void cargarDatos(){
        cargarUsuarios();
    }

    public void cargarUsuarios(){
        while(arch.hasNext()){
            Usuario usuario = new Usuario();
            if (!usuario.leer(arch)) break;
            usuarios.add(usuario);
        }
    }

    public void imprimirReporte(){
        System.out.println("=".repeat(90));
        for (Usuario usuario : usuarios){
            System.out.println(usuario);
        }
    }
}
