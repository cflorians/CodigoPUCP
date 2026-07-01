public class Principal {
    public static void main(String[] args) {
        // Creamos nuestro objeto auto
        // Como auto es abstracto, no lo podemos instanciar
        // Auto miAuto = new Auto("Kia", "Soul");
        // System.out.println(miAuto);
        // miAuto.imprimir();

        // El puntero a clase se hace definiendo un padre con dentro un new de la clase hijo
        Auto auto1 = new AutoElectrico("Tesla", "Model X", 520);
        Auto auto2 = new AutoHibrido("Toyota", "Rav4", 10);
        Auto auto3 = new AutoGasolina("Porsche", "911 Spider", 12);
        // imprimimos el metodo sobrescrito
        auto1.imprimir();
        auto1.tipoCombustible();

        auto2.imprimir();
        auto2.tipoCombustible();

        auto3.imprimir();
        auto3.tipoCombustible();
    }
}
