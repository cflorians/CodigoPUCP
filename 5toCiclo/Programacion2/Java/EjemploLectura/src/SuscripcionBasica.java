public class SuscripcionBasica extends Suscripcion{
    @Override
    public String getTipo() {
        return "Basica";
    }

    @Override
    public double calcularPrecio() {
        return 50;
    }
}
