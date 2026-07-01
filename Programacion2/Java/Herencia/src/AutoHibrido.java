public class AutoHibrido extends Auto{
    // atributos
    private int tiempoVida;

    public AutoHibrido(String marca, String modelo, int tiempoVida) {
        super(marca, modelo);
        this.tiempoVida = tiempoVida;
    }

    @Override
    public void tipoCombustible() {
        System.out.println("Auto Hibrido");
    }
}
