public class Hilo extends Thread {

    public static void main(String...args) {
	Hilo hilo = new Hilo();
	hilo.start();
    }

    public void run() { // Este va ejecutar el hilo
	for (int i = 0; i < 100; i++) {
	    System.out.println("Soy un hilo");
	}
	    
    }
}
