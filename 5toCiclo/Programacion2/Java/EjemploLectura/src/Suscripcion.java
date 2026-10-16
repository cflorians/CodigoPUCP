import java.util.Scanner;

public abstract class Suscripcion extends Registro{
    private int idUsuario;
    private int idCanal;
    private Usuario usuario;
    private Canal canal;

    public int getIdUsuario() {
        return idUsuario;
    }

    public void setIdUsuario(int idUsuario) {
        this.idUsuario = idUsuario;
    }

    public int getIdCanal() {
        return idCanal;
    }

    public void setIdCanal(int idCanal) {
        this.idCanal = idCanal;
    }

    public Usuario getUsuario() {
        return usuario;
    }

    public void setUsuario(Usuario usuario) {
        this.usuario = usuario;
    }

    public Canal getCanal() {
        return canal;
    }

    public void setCanal(Canal canal) {
        this.canal = canal;
    }

    public abstract String getTipo();
    public abstract double calcularPrecio();

    @Override
    public boolean leer(Scanner arch) {
        if (arch.hasNext()) return false;

        this.idUsuario = arch.nextInt();
        this.idCanal = arch.nextInt();

        return true;
    }

    @Override
    public void imprimir() {
        System.out.println(this);
    }
}
