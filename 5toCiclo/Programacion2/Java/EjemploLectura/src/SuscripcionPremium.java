public class SuscripcionPremium extends Suscripcion{
    @Override
    public String getTipo() {
        return "Premium";
    }

    @Override
    public double calcularPrecio() {
        return 80;
    }
}
