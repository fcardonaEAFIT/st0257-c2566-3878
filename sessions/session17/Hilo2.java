public class Hilo2 implements Runnable {

    public static void main(String...args) {
	Thread t = new Thread(new Hilo2());
	t.start();
    }

    public void run() { // Este va ejecutar el hilo
	for (int i = 0; i < 100; i++) {
	    System.out.println("Soy un hilo");
	}
	    
    }
}
