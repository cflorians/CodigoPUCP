public class AutoElectrico extends Auto{
    // atributos
    private double autonomia;

    public AutoElectrico(String marca, String modelo, double autonomia){
        super(marca, modelo);
        this.autonomia = autonomia;
    }

    @Override
    public void tipoCombustible() {
        System.out.println("Auto Electrico");
    }
}
