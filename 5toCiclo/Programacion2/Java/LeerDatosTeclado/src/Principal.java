import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
// NOMBRE: Carlos Florian
public class Principal {
    public static void main(String[] args) {
        try {
//            System.out.println("Ingrese un entero: ");
//
            // Creamos un objeto Scanner
            Scanner entrada = new Scanner(System.in);
//
//            // Usamos un metodo de Scanner para leer un numero que el usuario escriba
//            int num = entrada.nextInt();
//            System.out.println("num = " + num);
//
//            System.out.println("Ingrese un real: ");
//            double real = entrada.nextDouble();
//            System.out.println("Real = " + real);
//
//            System.out.println("Ingrese una cadena: ");
//            String cadena = entrada.next();
//            System.out.println("cadena = " + cadena);
//
//            entrada.nextLine(); // limpia buffer
//            System.out.println("Ingrese toda una linea:");
//            String linea = entrada.nextLine();
//            System.out.println("linea = " + linea);
//
//            // lectura de char
//            System.out.println("Ingrese un char:");
//            char caracter = entrada.next().charAt(0);
//            System.out.println("caracter = " + caracter);
//
//            // Lectura con limite de caracteres
//            String primeraPalabra = linea.substring(0,3);
//            System.out.println("primeraPalabra = " + primeraPalabra);

            String[] frutas = {"platano", "fresa", "uva", "papaya"};
            // ArrayList
            ArrayList<String> array = new ArrayList<>();
            // llena arreglo
            for (String fruta : frutas){
                array.add(fruta);
            }

            // imprime arreglo
            int i = 1;
            for (String fruta : array){
                System.out.println("fruta " + i + " = " + fruta);
                i++;
            }

            Collections.sort(array);
            // imprime el arreglo automaticamente
            System.out.println(array);

            entrada.close();
        }
        catch (Exception e) {
            System.out.println("Error = " + e);
        }
    }
}
