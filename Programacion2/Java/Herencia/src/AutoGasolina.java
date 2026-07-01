public class AutoGasolina extends Auto{
    // atributo
    private int capacidad; // tanque de gasolina

    public AutoGasolina(String marca, String modelo, int cap) {
        super(marca, modelo); // aca se llama al metodo constructor de la clase padre
        capacidad = cap;
    }

    @Override
    public void tipoCombustible() {
        System.out.println("Auto a Gasolina");
    }
}
